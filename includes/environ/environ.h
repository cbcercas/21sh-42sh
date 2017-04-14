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

t_array	*sh_init_environ(void);
t_array	*sh_get_envs(void);
t_env	*sh_getenv(char const *name);
t_env	*sh_setenv(char const *name, char const *value);
char	**sh_tenv_to_tab(void);
char	*sh_getenv_value(const char *name);

#endif