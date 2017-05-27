# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/05/24 16:26:26 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Minishell

SRC_SUBDIR		= core
SRCS			+= main.c prompt.c init.c input.c command.c check_path.c help.c

SRC_SUBDIR		+= environ
SRCS			+= environ.c env_list_utils.c getter_env.c

SRC_SUBDIR		+= builtins
SRCS			+= builtins_utils.c exit.c echo.c chdir.c

SRC_SUBDIR		+= lexer
SRCS			+= lexer_init.c lexer.c lexer_clean.c

SRC_SUBDIR		+= automaton
SRCS			+= automaton.c

SRC_SUBDIR		+= signals
SRCS			+= signals.c signals_handler.c

SRC_SUBDIR		+= parser
SRCS			+= parser.c parser_grammar.c

SRC_SUBDIR      += tests
SRCS            += env.c lexer_tests.c parser_tests.c

SRC_SUBDIR      += term
SRCS            += term_modes.c

SRC_SUBDIR      += tcaps
SRCS            += tcaps_exec_arrow.c tcaps_exec_backspace.c \
                    tcaps_exec_ctrl_1.c tcaps_exec_ctrl_2.c tcaps_exec_tab.c \
                    tcaps_key_exec.c

###############################################################################
#																			  #
#									CONFIG									  #
#																			  #
###############################################################################
#  Compiler
CC			= clang
CFLAGS		= -g -Wall -Wextra -Werror

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
#LIBS_FOLDER	= lib
## libcbc
LIB_CBC_DIR := libcbc

# libft:
INC += -I $(LIB_CBC_DIR)/libft/includes
# ftprintf:
INC += -I $(LIB_CBC_DIR)/libftprintf/includes
# logger:
INC += -I $(LIB_CBC_DIR)/liblogger/includes
# tcaps:
INC += -I $(LIB_CBC_DIR)/libtcaps/includes

LIBS += -L $(LIB_CBC_DIR) -lcbc

## Curses
LIBS                            += -lcurses

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INC)
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
	make -C $(LIB_CBC_DIR)
#	@make -C $(LIBFT_DIR)
#	@make -C $(LIBTCAPS_DIR)
re: clean fclean all

clean:
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)
	@make clean -C $(LIB_CBC_DIR)

fclean: clean
	@echo "\033[35mMinishell  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
	@make fclean -C $(LIB_CBC_DIR)

dev:
	@make -C ./ SAN="yes" DEV="yes"

.PHONY: re clean fclean all lib
.SUFFIXES: .c .h .o .d
