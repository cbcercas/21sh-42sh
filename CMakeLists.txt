cmake_minimum_required(VERSION 3.6)
project(Minishell)

set(CMAKE_CXX_STANDARD 11)
#set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(SOURCE_FILES
        includes/automaton/automaton.h
        includes/builtins/builtins_utils.h
        includes/builtins/chdir.h
        includes/builtins/echo.h
        includes/builtins/exit.h
        includes/core/check_path.h
        includes/core/command.h
        includes/core/data.h
        includes/core/init.h
        includes/core/input.h
        includes/core/main.h
        includes/core/help.h
        includes/core/prompt.h
        includes/environ/env_list_utils.h
        includes/environ/environ.h
        includes/lexer/lexer.h
        includes/tests/lexer_tests.h
        srcs/automaton/automaton.c
        srcs/builtins/builtins_utils.c
        srcs/builtins/chdir.c
        srcs/builtins/echo.c
        srcs/builtins/exit.c
        srcs/core/check_path.c
        srcs/core/command.c
        srcs/core/init.c
        srcs/core/input.c
        srcs/core/main.c
        srcs/core/help.c
        srcs/core/prompt.c
        srcs/environ/env_list_utils.c
        srcs/environ/environ.c
        srcs/lexer/lexer_init.c
        srcs/lexer/lexer.c
        srcs/lexer/lexer_clean.c
        srcs/term/term_modes.c
        srcs/tests/lexer_tests.c
        srcs/tests/env.c
        srcs/parser/parser.c
        srcs/parser/parser_grammar.c)

include_directories(includes)

#Libft
add_subdirectory(lib/libft)
include_directories(lib/libft/includes)

#Libtcaps
add_subdirectory(lib/libtcaps)
include_directories(lib/libtcaps/includes)

add_executable(Minishell ${SOURCE_FILES})

target_link_libraries(Minishell ft tcaps curses)
