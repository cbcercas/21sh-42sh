/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:43:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/08/04 09:24:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

# include <array/array.h>

/*
** @file   environ.h
**
** @brief  Function prototypes for the environ module
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   environ.c
**
** @brief  Functions for the environ module
*/


t_array	*init_environ(char **environ);
t_array	*init_local_var(void);
char	**var_to_tab(t_array *vars);

#endif
