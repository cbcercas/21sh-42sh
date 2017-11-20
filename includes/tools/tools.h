/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:00:38 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 15:16:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include <sys/stat.h>
#include <libft.h>
#include <environ/getter_env.h>
#include <environ/env_utils.h>
#include <parser/enum.h>

/*
** @file getpwd.c
**
** @brief Contains functions used to get the pwd
*/

char	*get_pwd(void);

/*
** @file is_printstr.c
**
** @brief Contains functions to test if string is printable
*/

BOOL	is_printstr(char const *line);

/*
** @file is.c
**
** @brief Contains functions used to checks tokens
*/

BOOL  is_white(int c);
BOOL  is_str_car(const char *buff);
BOOL  is_redirect(int c);
BOOL  is_sepa(int c);

/*
** @file sh_test_access.c
**
** @brief Functions used to test access to a file/path
*/

int		sh_test_access(char const *filename);

/*
** @file ft_isdigit_str.c
**
** @brief Functions used to test if the string is made of digits
*/

BOOL	ft_isdigit_str(char *str);



#endif
