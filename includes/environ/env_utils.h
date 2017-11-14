/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ENV_UTILS_H
#define BUILTIN_ENV_UTILS_H

# include <array/array.h>
# include "env_list_utils.h"

void print_vars(t_array *vars);
t_array	*get_envs(void);
t_array		*get_vars(void);
void sh_free_elem_env(t_env *elem);
t_array			*clone_vars(t_array *vars, t_array *tmp);

#endif
