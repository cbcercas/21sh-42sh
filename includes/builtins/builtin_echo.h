/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:25 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/21 08:14:22 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ECHO_H
# define BUILTIN_ECHO_H

# include <core/data.h>
# include <libft.h>
# include <unistd/ft_unistd.h>
# include <ftprintf.h>

/*
** @file builtin_echo.h
**
** @brief Function prototypes for the echo builtin
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   builtin_echo.c
**
** @brief  Contains the functions for the builtin echo
*/

int	sh_echo(t_sh_data *data, char **arg);

#endif
