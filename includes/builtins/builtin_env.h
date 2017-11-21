/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:18:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 08:17:24 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ENV_H
# define BUILTIN_ENV_H

# include <core/data.h>
# include <builtins/builtin_help.h>
# include <environ/env_list_utils.h>
# include <environ/env_utils.h>
# include <environ/modif_env.h>
# include <unistd/ft_unistd.h>
# include <stdio.h>
# include <environ/environ.h>
# include <core/input.h>
# include <exec/check_path.h>
# include <signal.h>
# include <signals/signals.h>
# include <exec/exec.h>

/*
** @file builtin_env.h
**
** @brief Function prototypes for the env builtin
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   builtin_environ.c
**
** @brief  Contains the functions for setenv and unsetenv builtins
*/

int		sh_builtin_setenv(t_sh_data *data, char **args);
int		sh_builtin_unsetenv(t_sh_data *data, char **args);

/*
** @file   builtin_environ_env.c
**
** @brief  Contains the functions for env builtin
*/

int		sh_builtin_env(t_sh_data *data, char **args);

/*
** @file   builtin_environ_env_u.c
**
** @brief  TODO
*/

t_array *sh_builtin_env_u(t_array *tmp, char **argv);

/*
** @file   builtin_environ_env_i.c
**
** @brief  TODO
*/

t_array *sh_builtin_env_add(t_array *tmp, char **argv);

/*
** @file   builtin_environ_env_exec.c
**
** @brief  Call the functions to execute the env
*/

int		sh_builtin_env_exec(char **av, t_array *envs);

#endif
