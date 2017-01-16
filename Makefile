# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/01/16 10:01:43 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRCS_MAIN		= main.c

SRCS_CORE		= prompt.c environ.c

SRCS_ENVIRON	= env_list_utils.c
###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################

#  Compiler
CC			= clang
CFLAGS		= -v -Wall -Wextra -Werror

#The Directories, Source, Includes, Objects and Libraries
SRCS_DIR	= srcs
OBJS_DIR	= objs
DEPS_DIR	= .deps
LIBFT_DIR	= libft
VPATH 		= $(SRCS_DIR) $(SRCS_DIR)/core $(SRCS_DIR)/environ

#Flags, Libraries, Objects and Includes
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/%.c, $(SRCS_MAIN))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/core/%.c, $(SRCS_CORE))
SRCS		+= $(patsubst %.c,$(SRCS_DIR)/environ/%.c, $(SRCS_ENVIRON))
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
DEPS		= $(patsubst $(SRCS_DIR)%.c,$(DEPDIR)%.d,$(SRCS))
LIBFT_FILE	= $(LIBFT_DIR)/libft.a
INC			= -I includes -I includes/core -I includes/environ
## libft includes
INC			+= -I $(LIBFT_DIR)/includes -I $(LIBFT_DIR)/includes/ft_printf -I $(LIBFT_DIR)/includes/gnl

#Utils
RM					= rm -rf
MKDIR				= mkdir -p

# Commande
define CC-COMMAND
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
endef

define DEPS-COMMAND
	@$(CC) $(CFLAGS) $(INC) -MM -MT $(DEPS_DIR)/$(patsubst %.c,$(DEPS_DIR)/%.d, $(notdir $@)) $< -MF $@
endef

###############################################################################
#																			  #
#								DOT NOT EDIT BELOW							  #
#																			  #
###############################################################################

 ##############################
##  AUTO DEPENDENCY GENERATOR ##
 ##############################

$(DEPS_DIR)/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

$(DEPS_DIR)/core/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

$(DEPS_DIR)/environ/%.d: %.c
	@$(MKDIR) $(dir $@)
	@$(DEPS-COMMAND)

# Add dependency as prerequisites
-include $(DEPS)

 ##################################
##  END AUTO DEPENDENCY GENERATOR ##
 ##################################

 #########
## RULES ##
 #########

all: $(NAME)

re: clean fclean all

$(OBJS_DIR)/%.o: %.c $(DEPS_DIR)/%.d
	@echo "\033[K\033[35mMinishell core  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(OBJS_DIR)/core/%.o: %.c $(DEPS_DIR)/core/%.d
	@echo "\033[K\033[35mMinishell core  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(OBJS_DIR)/environ/%.o: %.c $(DEPS_DIR)/environ/%.d
	@echo "\033[K\033[35mMinishell core  :\033[0m [Compilation:\033[33m $^\033[0m]\033[1A"
	@$(MKDIR) $(dir $@)
	@$(CC-COMMAND)

$(NAME): $(LIBFT_FILE) $(OBJS)
	@echo "\033[K\033[35mMinishell  :\033[0m [Compilation:\033[33m des .o\033[0m][\033[32mOK!\033[0m]"
	@echo "\033[35mLIBFT  :\033[0m [Compilation:\033[33m $(NAME)\033[0m]"
	 @$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft $(INC)
	@echo "[\033[35m--------------------------------\033[0m]"
	@echo "[\033[36m------- Minishell Done ! -------\033[0m]"
	@echo "[\033[35m--------------------------------\033[0m]"

$(LIBFT_FILE):
	@make -C $(LIBFT_DIR)

clean:
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)

fclean: clean
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)

.PHONY: re clean fclean all
.PRECIOUS: $(DEPS_DIR)/%.d $(DEPS_DIR)/core/%.d $(DEPS_DIR)/environ/%.d
.SUFFIXES: .c .h .o .d