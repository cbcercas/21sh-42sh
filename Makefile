# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 11:02:51 by chbravo-          #+#    #+#              #
#    Updated: 2017/11/13 10:37:58 by chbravo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TODO fix indent, space before '\'...
NAME = 21sh

SRC_SUBDIR		= core
SRCS			+= sh_get_input.c main.c prompt.c init.c input.c usage_help.c \
 					input_utils.c deinit.c input_windows.c input_draw.c \
 					input_move.c input_utils_2.c sh_loop.c sh_option.c \
 					input_get.c

SRC_SUBDIR		+= environ
SRCS			+= environ.c env_list_utils.c getter_env.c env_utils.c\
					modif_env.c

SRC_SUBDIR		+= builtins
SRCS			+= builtin_chdir.c builtin_chdir_expand.c builtin_echo.c\
					builtin_environ.c builtin_environ_env.c\
					builtin_environ_env_exec.c builtin_environ_env_i.c\
					builtin_environ_env_u.c builtin_exit.c builtin_help_2.c\
					builtin_help.c builtin_history_acdws.c builtin_history.c\
					builtin_history_npr.c builtin_history_print.c\
					builtin_local_var.c builtin_pwd.c builtins_utils2.c\
					builtin_utils.c builtin_help_3.c


SRC_SUBDIR		+= exec
SRCS			+= check_path.c exec_tlist.c manage.c sh_exec.c\
					sh_exec_local_var.c sh_exec_pipe.c sh_exec_redir2.c\
					sh_exec_redir.c sh_heradoc.c sh_process_exec.c sh_fork.c\
					sh_open.c sh_pipe.c


SRC_SUBDIR		+= tools
SRCS			+= ft_isdigit_str.c getpwd.c is.c\
					is_printstr.c sh_ret.c sh_test_access.c

SRC_SUBDIR		+= lexer
SRCS			+= lexer_init.c lexer.c lexer_clean.c lexer_utils.c

SRC_SUBDIR		+= signals
SRCS			+= signals.c signals_handler.c get_pid_childs.c

SRC_SUBDIR		+= automaton
SRCS			+= automaton.c

SRC_SUBDIR		+= parser
SRCS			+= parser.c

SRC_SUBDIR		+= expand
SRCS			+= expand.c expand_dol.c expand_history.c\
					expand_history_tools.c expand_merge.c expand_print.c\
					expand_quote.c expand_utils.c ft_replace.c

SRC_SUBDIR		+= tests
SRCS			+= ast_tests.c env_tests.c exec_tests.c expand_tests.c\
					lexer_tests.c local_var_tests.c parser_tests.c


SRC_SUBDIR		+= term
SRCS			+= term_modes.c

SRC_SUBDIR		+= history
SRCS			+= history_arrow.c history.c history_getter_2.c\
					history_getter.c history_input_utils.c history_list_utils.c\
					history_print.c history_research.c\
					history_research_start_end.c history_init.c


SRC_SUBDIR		+= tcaps
SRCS			+= clean_term.c get_curs_x.c get_curs_y.c\
					tcaps_exec_alt_arrows.c tcaps_exec_alt_c.c\
					tcaps_exec_alt_v.c tcaps_exec_arrow.c\
					tcaps_exec_backspace.c tcaps_exec_ctrl_1.c\
					tcaps_exec_ctrl_2.c tcaps_exec_delete.c\
					tcaps_exec_end_home.c tcaps_exec_select.c tcaps_exec_tab.c\
					tcaps_key_exec.c tcaps_redraw_line.c

SRC_SUBDIR		+= btree
SRCS			+= btree_create_node.c btree_apply.c btree_print.c btree_utils.c

SRC_SUBDIR      += ast
SRCS            += ast.c ast_utils.c ast_built.c ast_is_redir.c ast_cmp.c

SRC_SUBDIR		+= autocomplete
SRCS			+= autocomplete_is.c autocomplete_get_words.c\
					autocomplete_get_path.c autocomplete.c\
					autocomplete_display.c autocomplete_get_bin.c\
					autocomplete_utils.c autocomplete_sort.c\
					autocomplete_display_cols.c

SRC_SUBDIR		+= secure_memory
SRCS			+= ft_secu_free_all.c ft_secu_free.c ft_secu_malloc.c\
				ft_secu_malloc_get.c ft_secu_malloc_lvl.c ft_secu_free_lvl.c\
				string_dup_secu.c string_growth_secu.c string_insert_secu.c\
				string_secu.c ft_strdblfree.c ft_strdup_secu.c\
				ft_str_insert_secu.c ft_strjoincl_secu.c ft_strnew_secu.c\
				ft_strsplit_secu.c ft_strsub_secu.c

###############################################################################
#                                 CONFIG                                      #
###############################################################################

#  Compiler
CC                      = clang
CFLAGS          = -g -Wall -Wextra -Werror

ifeq ($(DEV),yes)
		CFLAGS          += -std=c11 -pedantic -pedantic-errors
endif

ifeq ($(SAN),yes)
		LDFLAGS += -fsanitize=address
		CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

ifeq ($(NOERR),yes)
    CFLAGS		= -g -Wall -Wextra -Wdeprecated-declarations
endif

#The Directories, Source, Includes, Objects and Libraries
INC                     = -I includes
SRCS_DIR        = srcs
vpath  %c $(addprefix $(SRCS_DIR)/,$(SRC_SUBDIR))

#Objects
OBJS_DIR        = objs
OBJS            = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Dependencies
DEPS_DIR        = .deps
DEPS            = $(SRCS:%.c=$(DEPS_DIR)/%.d)
BUILD_DIR       = $(OBJS_DIR) $(DEPS_DIR)

# Libraries
#LIBS_FOLDER    = lib
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
RM                                      = rm -rf
MKDIR                           = mkdir -p
COUNT_OBJ = 0
COUNT_DEP = 0
TOTAL = 0
PERCENT = 0
$(eval TOTAL=$(shell echo $$(printf "%s" "$(SRCS)" | wc -w)))

#color
C_NO = \033[0m
C_G = \033[0;32m
C_Y = \033[1;33m
C_B = \033[1;34m
C_C = \033[1;36m
C_R = \033[1;31m
C_P = \033[1;35m
DOXYGEN = $(shell doxygen -v dot 2> /dev/null)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	ECHOLOR = echo -e
endif
ifeq ($(UNAME_S), Darwin)
	ECHOLOR = echo
endif

###############################################################################
#                           DOT NOT EDIT BELOW                                #
###############################################################################

 #########
## RULES ##
 #########

#.SECONDARY: $(OBJS) lib

.NOTPARALLEL:
all: $(DEPS) lib $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INC)
		@$(ECHOLOR) "$(C_G)🎩🎩🎩$(C_NO) ALL LINKED $(C_G)🎩🎩🎩$(C_NO)"
		@$(ECHOLOR) "INFO: Flags: $(CFLAGS)"
		@$(ECHOLOR) "[\033[35m---------------------------------\033[0m]"
		@$(ECHOLOR) "[\033[36m---------- 21sh Done ! ----------\033[0m]"
		@$(ECHOLOR) "[\033[35m---------------------------------\033[0m]"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
		# Add dependency as prerequisites
		@-include $(DEPS)
		@$(CC) $(LDFLAGS) $(CFLAGS) $(INC) -o $@ -c $<
		$(eval COUNT_OBJ=$(shell echo $$(($(COUNT_OBJ)+1))))
		$(eval PERCENT=$(shell echo $$((($(COUNT_OBJ) * 100 )/$(TOTAL)))))
		@printf "$(C_B)%-8s $(C_P) $<$(C_NO)\n" "[$(PERCENT)%]"

$(DEPS_DIR)/%.d: %.c | $(DEPS_DIR)
		@$(CC) $(INC) -MM $< -MT $(OBJS_DIR)/$*.o -MF $@

$(BUILD_DIR):
		@$(MKDIR) -p $@

lib:
		@make -C $(LIB_CBC_DIR)

re: fclean $(DEPS) lib $(NAME)

clean:
	@$(ECHOLOR) "\033[35m21sh  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@$(ECHOLOR) "\033[35m21sh  :\033[0m [\033[31mSuppression des .d\033[0m]"
	@$(RM) $(DEPS_DIR)
	@make clean -C $(LIB_CBC_DIR)

fclean: clean
	@$(ECHOLOR) "\033[35m21sh  :\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@$(RM) $(NAME)
	@make fclean -C $(LIB_CBC_DIR)
	@rm -rf DOC

dev:
		@make -C ./ SAN="yes" DEV="yes"

doc:
ifndef DOXYGEN
		@echo $(DOXYGEN)
		@echo "Please install doxygen and graphviz first (brew install doxygen graphviz)."
else
	/bin/bash scripts/DCG.sh && doxygen Doxyfile && /bin/bash scripts/NCG.sh
	@$(ECHOLOR) "[\033[35m--------------------------\033[0m]"
	@$(ECHOLOR) "[\033[36m------ Documentation -----\033[0m]"
	@$(ECHOLOR) "[\033[36m------   generated   -----\033[0m]"
	@$(ECHOLOR) "[\033[35m--------------------------\033[0m]"
endif

.PHONY: re clean fclean all lib doc dev
.SUFFIXES: .c .h .o .d
