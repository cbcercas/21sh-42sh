/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:06:22 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/09 18:35:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PATH_H
# define CHECK_PATH_H

# include <libft.h>
# include <tools/tools.h>
# include <secure_memory/ft_secu_malloc.h>
# include <ftprintf.h>
# include <core/progname.h>
# include <stdio.h>

/*
** @file   check_path.h
**
** @brief  Function prototypes to check the path
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   check_path.c
**
** @brief  Functions to check the path and parse it
*/

char	*sh_check_path(char const *cmd_name);
char	*get_filename(char *av);
char	*makefilepath(char const *path, char const *filename);

#endif
