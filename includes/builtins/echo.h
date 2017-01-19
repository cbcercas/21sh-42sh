/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:25 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/19 15:22:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ECHO_H
# define ECHO_H
# include "libft.h"
# include "libftprintf.h"
# include "parsing_command.h"
# include "data.h"
# include "command.h"

typedef struct s_echo
{
	char			cur_q;
	int				lvl;
}				t_echo;

int	ms_echo(t_ms_data *data, char *arg);

#endif