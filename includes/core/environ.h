/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:43:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/29 14:40:37 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H
# include "env_list_utils.h"

t_env	*ms_copy_environ(void);
char	*ms_getenv(t_env *env, char *name);
t_env	*ms_setenv(t_env *env, char *name, char *value);

#endif