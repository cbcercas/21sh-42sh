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

char	*get_pwd(void);
BOOL	is_printstr(char const *line);
BOOL  is_white(int c);
BOOL  is_str_car(const char *buff);
BOOL  is_redirect(int c);
BOOL  is_sepa(int c);
int		sh_test_access(char const *filename);
BOOL	ft_isdigit_str(char *str);
BOOL	check_fd(int fd);;


#endif
