/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTER_ENV_H
# define GETTER_ENV_H

# include <array/array.h>
# include "env_list_utils.h"

/*
** @file   getter_env.h
**
** @brief  Function prototypes to get the env
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   getter_env.c
**
** @brief  Functions used to get the env
*/

char	*get_var_value(t_array *vars, const char *name);
t_env	*get_var(t_array *vars, const char *name);

#endif
