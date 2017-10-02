cmake_minimum_required(VERSION 3.0)
project(21sh)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "-g -Wall -Werror -Wextra")

set(SOURCE_FILES

		srcs/autocomplete/autocomplete.c
		srcs/autocomplete/autocomplete_display.c
		srcs/autocomplete/autocomplete_get_bin.c
		srcs/autocomplete/autocomplete_get_path.c
		srcs/autocomplete/autocomplete_get_words.c
		srcs/autocomplete/autocomplete_is.c

		srcs/automaton/automaton.c

		srcs/ast/ast_utils.c
		srcs/ast/ast_built.c
		srcs/ast/ast_is_greatand.c
		srcs/ast/ast.c

		srcs/btree/btree_apply_infix.c
		srcs/btree/btree_apply_suffix.c
		srcs/btree/btree_apply_prefix.c
		srcs/btree/btree_destroy.c
		srcs/btree/btree_insert_data.c
		srcs/btree/btree_create_node.c
		srcs/btree/btree_print.c
		srcs/btree/btree_level_count.c
		srcs/btree/btree_search_item.c

		srcs/builtins/builtins_utils.c
		srcs/builtins/builtins_utils2.c
		srcs/builtins/builtin_chdir.c
		srcs/builtins/builtin_echo.c
		srcs/builtins/builtin_exit.c
		srcs/builtins/builtin_help.c
		srcs/builtins/builtin_pwd.c
		srcs/builtins/builtin_environ.c
		srcs/builtins/builtin_environ_env.c
		srcs/builtins/builtin_environ_env_exec.c
		srcs/builtins/builtin_environ_env_i.c
		srcs/builtins/builtin_environ_env_u.c
		srcs/builtins/builtin_history.c
		srcs/builtins/builtin_history_acdws.c
		srcs/builtins/builtin_history_print.c
		srcs/builtins/builtin_history_npr.c

		srcs/core/init.c
		srcs/core/deinit.c
		srcs/core/input.c
		srcs/core/input_utils.c
		srcs/core/main.c
		srcs/core/usage_help.c
		srcs/core/prompt.c

		srcs/environ/env_list_utils.c
		srcs/environ/environ.c
		srcs/environ/getter_env.c
		srcs/environ/builtin_env_utils.c
		srcs/environ/modif_env.c

		srcs/exec/check_path.c
		srcs/exec/sh_process_exec.c
		srcs/exec/sh_exec.c
		srcs/exec/sh_exec_pipe.c
		srcs/exec/sh_exec_redir.c

		srcs/expand/expand.c
		srcs/expand/expand_dol.c
		srcs/expand/expand_history.c
		srcs/expand/expand_history_tools.c
		srcs/expand/expand_merge.c
		srcs/expand/expand_print.c
		srcs/expand/expand_quote.c
		srcs/expand/expand_utils.c
		srcs/expand/ft_replace.c

		srcs/ft_secu_malloc/ft_secu_free.c
		srcs/ft_secu_malloc/ft_secu_free_all.c
		srcs/ft_secu_malloc/ft_secu_free_lvl.c
		srcs/ft_secu_malloc/ft_secu_malloc.c
		srcs/ft_secu_malloc/ft_secu_malloc_get.c
		srcs/ft_secu_malloc/ft_secu_malloc_lvl.c

		srcs/history/history.c
		srcs/history/history_list_utils.c
		srcs/history/history_getter.c
		srcs/history/history_print.c
		srcs/history/history_arrow.c
		srcs/history/history_research.c
		srcs/history/history_research_start_end.c

		srcs/lexer/lexer_init.c
		srcs/lexer/lexer.c
		srcs/lexer/lexer_clean.c


		srcs/parser/parser.c
		srcs/parser/parser_grammar.c

		srcs/signals/signals.c
		srcs/signals/signals_handler.c

		srcs/tcaps/tcaps_exec_alt_arrows.c
		srcs/tcaps/tcaps_exec_arrow.c
		srcs/tcaps/tcaps_exec_backspace.c
		srcs/tcaps/tcaps_exec_ctrl_1.c
		srcs/tcaps/tcaps_exec_ctrl_2.c
		srcs/tcaps/tcaps_exec_delete.c
		srcs/tcaps/tcaps_exec_end_home.c
		srcs/tcaps/tcaps_exec_select.c
		srcs/tcaps/tcaps_exec_tab.c
		srcs/tcaps/tcaps_key_exec.c
		srcs/tcaps/tcaps_redraw_line.c
		srcs/tcaps/clean_term.c
		srcs/tcaps/get_curs_x.c
		srcs/tcaps/get_curs_y.c

		srcs/term/term_modes.c

		srcs/tools/ft_isdigit_str.c
		srcs/tools/ft_strnew_secu.c
		srcs/tools/ft_strsub_secu.c
		srcs/tools/sh_ret.c
		srcs/tools/ft_strsplit_secu.c
		srcs/tools/ft_strdblfree.c
		srcs/tools/is_printstr.c
		srcs/tools/sh_fork.c
		srcs/tools/sh_pipe.c
        srcs/tools/sh_open.c
		srcs/tools/ft_str_insert_secu.c
		srcs/tools/ft_strdup_secu.c
		srcs/tools/ft_strjoincl_secu.c
		srcs/tools/string_dup_secu.c
		srcs/tools/string_growth_secu.c
		srcs/tools/string_insert_secu.c
		srcs/tools/string_secu.c

		srcs/tests/lexer_tests.c
		srcs/tests/env_tests.c
		srcs/tests/parser_tests.c
		srcs/tests/env_tests.c
		srcs/tests/expand_tests.c
		srcs/tests/ast_tests.c
		srcs/tests/exec_tests.c
        srcs/builtins/builtin_help_2.c)

include_directories(includes)

#Libcbc
add_subdirectory(libcbc)
include_directories(libcbc/libft/includes libcbc/libftprintf/includes libcbc/liblogger/includes libcbc/libtcaps/includes)

add_executable(21sh ${SOURCE_FILES})

target_link_libraries(21sh cbc curses)
