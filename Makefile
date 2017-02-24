# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/02/19 18:04:43 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRC_SUBDIR		= core
SRCS			+= main.c prompt.c init.c input.c command.c parsing_command.c

SRC_SUBDIR		+= environ
SRCS			+= environ.c env_list_utils.c

SRC_SUBDIR		+= builtins
SRCS			+= builtins_utils.c exit.c echo.c chdir.c
###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################
#  Compiler
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

ifeq ($(DEV),yes)
	CFLAGS		+= -std=c11 -pedantic -pedantic-errors
endif

ifeq ($(SAN),yes)
	LDFLAGS += -fsanitize=address
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

#The Directories, Source, Includes, Objects and Libraries
INC			= -I includes
SRCS_DIR	= srcs
vpath  %c $(addprefix $(SRCS_DIR)/,$(SRC_SUBDIR))

#Objects
OBJS_DIR	= objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Dependencies
DEPS_DIR	= .deps
DEPS		= $(SRCS:%.c=$(DEPS_DIR)/%.d)
BUILD_DIR	= $(OBJS_DIR) $(DEPS_DIR)

# Libraries
LIBS_FOLDER	= lib
## libft
LIBFT_DIR	= $(LIBS_FOLDER)/libft
LIBFT_FILE	= $(LIBFT_DIR)/libft.a
INC			+= -I $(LIBFT_DIR)/includes

#Utils
RM					= rm -rf
MKDIR				= mkdir -p

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################
 #########
## RULES ##
 #########
.SECONDARY: $(OBJS) lib

all: $(DEPS) $(NAME)

# Add dependency as prerequisites
-include $(DEPS)

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft $(INC)
	@echo "[\033[35m---------------------------------\033[0m]"
	@echo "[\033[36m-------- Minishell Done ! -------\033[0m]"
	@echo "[\033[35m---------------------------------\033[0m]"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(LDFLAGS) $(INC) -o $@ -c $<

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
	$(CC) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@

$(BUILD_DIR):
	@$(MKDIR) -p $@

lib:
	@make -C $(LIBFT_DIR)

re: clean fclean all

clean:
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

.PHONY: re clean fclean all lib
.SUFFIXES: .c .h .o .d