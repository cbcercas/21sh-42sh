/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:59:00 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 16:49:47 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# include <automaton/automaton.h>

/*
** @file   help.h
**
** @brief  Function prototypes for the help (-h --help)
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file usage_help.c
**
** @brief Contains the functions used to display the usage help
*/

void		sh_usage_help(void);
void		sh_usage_help_exit(void);
void		sh_over(char *mess, t_automaton *automat, t_array *array,\
														void fn(void *elem));
#endif
