/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:31 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/21 08:16:04 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_EXIT_H
# define BUILTIN_EXIT_H

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

void	sh_exit(t_sh_data *data, char **arg);
int		builtin_exit(t_sh_data *data, char **arg);

/*
** builtin_exit() calls sh_exit. This is just for code understanding
*/

#endif
