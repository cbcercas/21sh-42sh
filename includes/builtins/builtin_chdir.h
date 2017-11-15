/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:34:02 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 16:47:09 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHDIR_H
# define CHDIR_H

# include <core/data.h>
# include <libft.h>
# include <builtins/builtin_exit.h>
# include <tools/tools.h>
# include <ftprintf.h>
# include <core/input.h>
# include <core/progname.h>
# include <environ/modif_env.h>
# include <unistd/ft_unistd.h>
# include <builtins/builtin_echo.h>

/*
** @file builtin_chdir.h
**
** @brief Function prototypes for
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   builtin_chdir.c
**
** @brief  Contains the functions for chdir (cd)
*/

int		sh_chdir(t_sh_data *data, char **arg);

/*
** @file   builtin_chdir_expand.c
**
** @brief  Contains the functions for the expand part of chdir (cd)
*/
char	*expand_path(char **path);




#endif