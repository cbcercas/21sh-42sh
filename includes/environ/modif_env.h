/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIF_ENV_H
# define MODIF_ENV_H

# include <array/array.h>
# include "env_list_utils.h"

/*
** @file   modif_env.h
**
** @brief  Function prototypes to modify the env
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   modif_env.c
**
** @brief  Functions used to modify the env
*/


t_env	*del_var(t_array *vars, char const *name);
t_env	*set_var(t_array *vars, char const *name,
				char const *value, BOOL is_export);

#endif
