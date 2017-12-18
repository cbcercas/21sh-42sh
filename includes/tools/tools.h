/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:00:38 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 14:20:08 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <sys/stat.h>
# include <libft.h>
# include <environ/getter_env.h>
# include <environ/env_utils.h>
# include <parser/enum.h>

/*
** @file tools.h
**
** @brief This file contains the prototypes of the utility tools used in the
** program
*/

/*
** @file getpwd.c
**
** @brief Contains functions used to get the pwd
*/

char		*get_pwd(void);

/*
** @file is.c
**
** @brief Contains functions used to checks tokens
*/

BOOL		is_white(int c);
BOOL		is_str_car(const char *buff);
BOOL		is_redirect(int c);
BOOL		is_sepa(int c);
BOOL		is_printstr(char const *line);

/*
** @file sh_test_access.c
**
** @brief Functions used to test access to a file/path
*/

int			sh_test_access(char const *filename);

/*
** @file ft_isdigit_str.c
**
** @brief Functions used to test if the string is made of digits
*/

BOOL		ft_isdigit_str(char *str);

void		print_verb(char *line);
void		sh_exit_error(const char *error);
void	sh_exit_printf(const char *fmt, ...);

/*
** @file array_free_elem.c
**
** @brief Functions used to free array elems
*/

void		string_clear(void *string);

#endif
