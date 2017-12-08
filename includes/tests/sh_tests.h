/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/30 22:39:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TESTS_H
# define SH_TESTS_H

# include <automaton/automaton.h>
# include <lexer/lexer.h>
# include <ftprintf.h>
# include <ast/ast.h>
# include <history/history.h>
# include <environ/environ.h>
# include <environ/modif_env.h>
# include <builtins/builtin_utils.h>
# include <exec/exec.h>
# include <parser/parser.h>

/*
** @file sh_tests.h
**
** @brief This files contains all prototypes for the functions used to test
** this program
*/

/*
** @file env_tests.c
**
** @brief Functions used to test the env module
*/

void	sh_testing_env(char *const *av, char **environ);
void	sh_testing_env_set(char *const *av);
void	sh_testing_env_del(char *const *av);

/*
** @file ast_tests.c
**
** @brief Functions used to test the ast module
*/

void	sh_testing_ast(char *const *av, char **environ);

/*
** @file exec_tests.c
**
** @brief Functions used to test the exec module
*/

void	sh_testing_exec(char *const *av, char **environ);

/*
** @file local_var_tests.c
**
** @brief Functions used to test the local vars module
*/

void	testing_local_vars_set(char *const *av);
void	testing_local_vars_del(char *const *av);
void	testing_local_vars(char *const *av, char **environ);

/*
** @file parser_tests.c
**
** @brief Functions used to test the parser module
*/

void	sh_testing_parser(char *const *av);

/*
** @file lexer_tests.c
**
** @brief Functions used to test the lexer module
*/

void	sh_testing_lexer(char *const *av);

/*
** @file expand_tests.c
**
** @brief Functions used to test the expand module
*/

void	sh_testing_expand(char *const *av, char **environ);

#endif
