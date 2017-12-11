/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/11/21 08:20:13 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_HELP_H
# define BUILTIN_HELP_H

# include <ftprintf.h>
# include <core/data.h>
# include <core/color.h>
# include <core/progname.h>
# include <libft.h>

/*
** @file builtin_help.h
**
** @brief Function prototypes for the help builtin
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file   builtin_help.c
**
** @brief  Contains the functions for help display
*/

int		sh_builtin_help(t_sh_data *data, char **args);
void sh_help_default();
void	sh_help_help(void);
void	sh_help_echo(void);
void	sh_help_bonus(void);

/*
** @file   builtin_help_2.c
**
** @brief  Contains the functions for help display
*/

void	sh_help_exit(void);
void	sh_help_cd(void);
void	sh_help_chdir(void);
void	sh_help_env(void);
void	sh_help_setenv(void);
void	sh_help_unsetenv(void);

/*
** @file   builtin_help_3.c
**
** @brief  Contains the functions for help display
*/

int		sh_builtin_help_helper(char **args);
void	sh_help_history(void);
void	sh_help_history_helper(void);
void	sh_help_pwd(void);
void	sh_help_export(void);

#endif
