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

void	sh_testing_env(char *const *av, char **environ);
void	sh_testing_env_set(char *const *av);
void	sh_testing_env_del(char *const *av);

void	sh_testing_ast(char *const *av, char **environ);

void	sh_testing_exec(char *const *av, char **environ);

void	testing_local_vars_set(char *const *av);
void	testing_local_vars_del(char *const *av);
void	testing_local_vars(char *const *av, char **environ);

void	sh_testing_parser(char *const *av);
void	sh_testing_lexer(char *const *av);
void	sh_testing_expand(char *const *av, char **environ);

#endif
