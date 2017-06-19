/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:43:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 19:08:04 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H
# include <environ/env_list_utils.h>
# include <logger.h>

t_array	*sh_init_environ(void);
t_array	*sh_get_envs(void);
t_env	*sh_getenv(char const *name);
t_env	*sh_setenv(char const *name, char const *value);
t_env    *sh_delenv(char const *name);
char	**sh_tenv_to_tab(void);
int     sh_builtin_setenv(t_sh_data *data, char **args);
int     sh_builtin_unsetenv(t_sh_data *data, char **args);
char	*sh_getenv_value(const char *name);

#endif