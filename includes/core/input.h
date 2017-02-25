/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/23 21:00:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INPUT_H
# define INPUT_H
# include <libft.h>
# include <gnl/get_next_line.h>
# include <core/init.h>
# include <core/parsing_command.h>
# include <core/command.h>

//int		ms_get_command(t_ms_data	*data);

/**
** @file       input.c
**
** @brief      Functions to read the input
*/
char	*ms_get_line(void);

#endif