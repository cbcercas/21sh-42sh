/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/30 22:39:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <ftprintf.h>
# include <environ/environ.h>

void sh_testing_env(char *const *av, char **environ);
void	sh_testing_env_set(char *const *av);
void	sh_testing_env_del(char *const *av);
void	sh_testing_ast(char *const *av, char **environ);
void	sh_testing_exec(char *const *av, char **environ);

void	testing_local_vars_set(char *const *av);
void	testing_local_vars_del(char *const *av);
void	testing_local_vars(char *const *av, char **environ);

#endif //MINISHELL_TEST_H
