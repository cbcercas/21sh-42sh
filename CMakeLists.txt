cmake_minimum_required(VERSION 3.0)
project(21sh)

set(CMAKE_CXX_STANDARD 11)
#set (CMAKE_C_FLAGS "-g -Wall -Werror -Wextra")

set(SOURCE_FILES
        srcs/automaton/automaton.c
        srcs/builtins/builtins_utils.c
        srcs/builtins/builtins_utils2.c
        srcs/builtins/chdir.c
        srcs/builtins/echo.c
        srcs/builtins/exit.c
        srcs/core/check_path.c
        srcs/core/command.c
        srcs/core/init.c
        srcs/core/input.c
        srcs/core/input_utils.c
        srcs/core/main.c
        srcs/core/usage_help.c
        srcs/core/prompt.c
        srcs/environ/env_list_utils.c
        srcs/environ/environ.c
        srcs/environ/getter_env.c
        srcs/environ/builtin_env_utils.c
        srcs/environ/builtin_environ.c
        srcs/environ/modif_env.c
        srcs/lexer/lexer_init.c
        srcs/lexer/lexer.c
        srcs/lexer/lexer_clean.c
        srcs/term/term_modes.c
        srcs/tests/lexer_tests.c
        srcs/tests/env_tests.c
        srcs/tests/parser_tests.c
        srcs/parser/parser.c
        srcs/parser/parser_grammar.c
        srcs/signals/signals.c
        srcs/signals/signals_handler.c
        srcs/tcaps/tcaps_exec_arrow.c
        srcs/tcaps/tcaps_exec_backspace.c
        srcs/tcaps/tcaps_exec_delete.c
        srcs/tcaps/tcaps_exec_ctrl_1.c
        srcs/tcaps/tcaps_exec_ctrl_2.c
        srcs/tcaps/tcaps_exec_tab.c
        srcs/tcaps/tcaps_key_exec.c
        srcs/tcaps/tcaps_redraw_line.c
        srcs/tests/env_tests.c
        srcs/history/history.c
        srcs/history/history_list_utils.c
        srcs/history/history_getter.c
        srcs/history/history_print.c
        srcs/history/history_arrow.c
        srcs/history/history_research.c
        srcs/history/history_research_start_end.c
        srcs/builtins/builtin_history.c
        srcs/builtins/builtin_history_acdws.c
        srcs/builtins/builtin_history_print.c
        srcs/builtins/builtin_history_npr.c
        srcs/builtins/builtin_help.c
        srcs/builtins/pwd.c)

include_directories(includes)

#Libcbc
add_subdirectory(libcbc)
include_directories(libcbc/libft/includes libcbc/libftprintf/includes libcbc/liblogger/includes libcbc/libtcaps/includes)

add_executable(21sh ${SOURCE_FILES})

target_link_libraries(21sh cbc curses)
