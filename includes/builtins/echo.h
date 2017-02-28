/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:25 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/28 04:55:27 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ECHO_H
# define ECHO_H
# include <libft.h>
# include <ft_printf/libftprintf.h>
# include <core/data.h>
# include <core/command.h>
# include <builtins/builtins_utils.h>

typedef struct s_echo
{
	char			cur_q;
	int				lvl;
}				t_echo;

int	ms_echo(t_ms_data *data, char *arg);

#endif