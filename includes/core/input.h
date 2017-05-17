/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 22:24:22 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INPUT_H
# define INPUT_H
# include <string/ft_string.h>
# include <libtcaps.h>

//int		sh_get_command(t_ms_data	*data);

typedef struct s_input	t_input;
struct	s_input
{
	t_string	*str;
	size_t		offset;
	t_cpos		cpos;
};

/**
** @file       input.c
**
** @brief      Functions to read the input
*/
char	*sh_get_line(void);
char	*sh_get_line2(void);
void	reset_input(t_input *input);

#endif