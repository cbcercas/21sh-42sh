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
#include "return.h"

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
	t_return		prompt_type;
	//TODO possibly remove prompt len use only offset to simplfy long line
	size_t			prompt_len;
	unsigned short	offset_col;
	unsigned short	offset_line;
	unsigned short	offset_len;
	struct winsize	*ts;
	t_cpos			cpos;
	t_select		*select;
	BOOL			lock;
};

typedef struct s_window	t_window;
struct 					s_window
{
	t_input				*cur_head;
	t_input				*cur;
	t_input				*save;
	ssize_t 				histlvl;
	BOOL				histlock;
	struct winsize		ts;
	t_select			select;
};

/**
 * @file       input.c
 *
 * @brief      Functions to read the input
 */
char *sh_get_line(t_input *input, t_sh_opt *opts);
char	*sh_get_line2(void);
void			reset_input(t_input *input) __attribute__ ((deprecated("use input_reset instead")));
size_t	pos_in_str(t_input *input);
t_input	*input_new(void);
t_input *input_get_last(t_input *input);
t_input	*input_add_new(t_input *input);

void	input_destroy(t_input **input);
void	input_reset(t_input *input);
t_input *input_hard_reset(t_input **input);
t_input *input_from_history(const char *hist);
t_input *input_get_writable(t_input *input);
t_cpos	input_get_first_pos(t_input *input);
t_cpos	input_get_last_pos(t_input *input);

t_window		*get_windows(int rst);
t_select		*get_select(void);
struct winsize	*get_ts(void);
t_input			*input_get_cur_head(void);
t_input			*input_get_cur(void);

/*
 * input_draw.c
 */
void		draw_char(t_input *input, char *c);
void			redraw_input(t_input *inp);
t_input			*input_draw(t_input *input);

/*
 * input_move.c
 */
t_input			*input_back_to_origin(t_input *input);
void			input_goto_line_end(t_input *input);
//TODO Remove this
extern	t_input	*g_input __attribute__ ((deprecated("Us get_windows(0)-cur or get_windows(0)->cur_head")));

#endif
