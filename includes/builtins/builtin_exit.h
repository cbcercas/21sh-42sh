/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:31 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/12 11:21:31 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <core/data.h>
# include <history/history.h>
# include <core/deinit.h>
# include <signals/signals.h>

/*
** @file builtin_exit.h
**
** @brief Function prototypes for the exit builtin
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/


/*
** @file   builtin_exit.c
**
** @brief  Contains the functions for the exit builtin
*/

void sh_exit(t_sh_data *data, char **arg);
void builtin_exit(t_sh_data *data, char **arg);

/*
**builtin_exit() calls sh_exit. This is just for code understanding
*/
#endif
