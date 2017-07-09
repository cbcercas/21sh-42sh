/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/30 15:16:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include <string/ft_string.h>
# include <libtcaps.h>
# include <automaton/automaton.h>

//int		sh_get_command(t_ms_data	*data);

typedef struct s_input	t_input;
struct	s_input
{
	t_string	*str;
	size_t		offset_col;
	size_t		offset_line;
	t_ts		ts;
	t_cpos		cpos;
};

/**
** @file       input.c
**
** @brief      Functions to read the input
*/

void    sh_reset_line(t_automaton *automaton, t_array *tokens);
char	*sh_get_line(void);
char	*sh_get_line2(void);
void	reset_input(t_input *input);
size_t	sh_pos_of_insert(t_input input);

extern	t_input	*g_input;

#endif
