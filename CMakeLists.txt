cmake_minimum_required(VERSION 3.0)
project(Minishell)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "-g -Wall -Werror -Wextra")

set(SOURCE_FILES
        srcs/automaton/automaton.c
        srcs/builtins/builtins_utils.c
        srcs/builtins/chdir.c
        srcs/builtins/echo.c
        srcs/builtins/exit.c
        srcs/core/check_path.c
        srcs/core/command.c
        srcs/core/init.c
        srcs/core/input.c
        srcs/core/input_utils.c
        srcs/core/main.c
        srcs/core/help.c
        srcs/core/prompt.c
        srcs/environ/env_list_utils.c
        srcs/environ/environ.c
        srcs/environ/getter_env.c
        srcs/lexer/lexer_init.c
        srcs/lexer/lexer.c
        srcs/lexer/lexer_clean.c
        srcs/term/term_modes.c
        srcs/tests/lexer_tests.c
        srcs/tests/env.c
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
        srcs/tests/env.c
        )

include_directories(includes)

#Libcbc
add_subdirectory(libcbc)
include_directories(libcbc/libft_cbc/includes libcbc/libftprintfcbc/includes libcbc/lib_logger_cbc/includes libcbc/lib_tcaps/includes)

add_executable(Minishell ${SOURCE_FILES})

target_link_libraries(Minishell cbc curses)
