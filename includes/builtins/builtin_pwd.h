/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/11/21 08:18:45 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_PWD_H
# define BUILTIN_PWD_H

# include <core/data.h>
# include <stdio.h>
# include <sys/stat.h>
# include <environ/env_utils.h>
# include <environ/getter_env.h>
# include <unistd/ft_unistd.h>

/*
** @file builtin_pwd.h
**
** @brief Function prototypes for the pwd builtin
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   builtin_pwd.c
**
** @brief  This file contains the functions for the pwd builtin
*/

int sh_builtin_pwd(t_sh_data *data, char **args);

#endif
