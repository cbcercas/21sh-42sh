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

t_env	*ms_copy_environ(void);
char	*ms_getenv(t_env const *env, char const *name);
t_env	*ms_setenv(t_env *env, char const *name, char const *value);
char	**ms_tenv_to_tab(t_env const *env);

#endif