/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/20 16:14:17 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

#include <string/ft_string.h>
#include <libtcaps.h>
#include "data.h"

//int		sh_get_command(t_ms_data	*data);
typedef struct s_select t_select;
struct	s_select
{
	BOOL		is;
	size_t	cur_start;
	size_t	cur_end;
	char		*str;
};

typedef struct s_input	t_input;
struct	s_input
{
	t_input			*next;
	t_input			*prev;
	t_string		*str;
	BOOL			prompt;
	size_t			prompt_len;
	unsigned short	offset_col;
	unsigned short	offset_line;
	struct winsize	ts;
	t_cpos			cpos;
	t_select		select;
	size_t			len_save;
};

/**
 * @file       input.c
 *
 * @brief      Functions to read the input
 */
char *sh_get_line(t_input *input, t_sh_opt *opts);
char	*sh_get_line2(void);
void	reset_input(t_input *input);
size_t	pos_in_str(t_input *input);
t_input	*input_new(void);
t_input	*input_get(void);
t_input	*input_get_last(void);
t_input	*input_add_new(t_input *input);

void	input_destroy(t_input **input);
void	input_reset(t_input *input);

//TODO Remove this
extern	t_input	*g_input;

#endif
