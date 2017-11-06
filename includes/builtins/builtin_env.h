/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:18:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/04 12:22:39 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ENVIRON_H
#define BUILTIN_ENVIRON_H

# include <libft.h>
# include <logger.h>
# include <ftprintf.h>
# include <core/data.h>
# include <environ/getter_env.h>
# include <environ/modif_env.h>
# include <builtins/builtins_utils.h>

/**
 * @file   builtin_environ.c
 *
 * @brief  Contains the functions for setenv and unsetenv builtins
 */

int     sh_builtin_setenv(t_sh_data *data, char **args);
int     sh_builtin_unsetenv(t_sh_data *data, char **args);

/**
 * @file   builtin_environ_env.c
 *
 * @brief  Contains the functions for env builtin
 */

int		sh_builtin_env(t_sh_data *data, char **args);

/**
 * @file   builtin_environ_env_u.c
 *
 * @brief  ???
 */

t_array *sh_builtin_env_u(t_array *tmp, char **argv);

/**
 * @file   builtin_environ_env_i.c
 *
 * @brief  ???
 */

t_array *sh_builtin_env_add(t_array *tmp, char **argv);

/**
 * @file   builtin_environ_env_exec.c
 *
 * @brief  Call the functions to execute the env
 */

int sh_builtin_env_exec(char **av, t_array *envs);

#endif
