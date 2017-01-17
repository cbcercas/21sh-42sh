/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:40:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/17 08:47:55 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSING_COMMAND_H
# define PARSING_COMMAND_H
# include "libft.h"
# include "libftprintf.h"

typedef struct	s_command
{
	struct s_command	*next;
	char				*command;
	char				*args;
}				t_command;

t_command	*ms_parse_command(char *command);

#endif