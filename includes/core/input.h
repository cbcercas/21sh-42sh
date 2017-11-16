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

# include <string/ft_string.h>
# include <libtcaps.h>
# include "data.h"
# include "return.h"

/*
** @file   input.h
**
** @brief  Function prototypes for the input
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/


# define MAX_LEN_INPUT 1000
# define MAX_NB_INPUT 100

/*
** @struct s_select
**
** @brief TODO
**
** @arg TODO
*/


typedef struct s_select	t_select;
struct					s_select
{
	BOOL				is;
	char				*str;
	struct s_input		*start_abs;
};

/*
** @brief TODO
**
** @arg TODO
*/

typedef struct s_select_pos	t_select_pos;
struct					s_select_pos
{
	BOOL				is_set;
	size_t				cur_start;
	size_t				cur_end;
};

/*
** @struct s_input
**
** @brief TODO
**
** @arg TODO
*/

typedef struct s_input	t_input;
struct					s_input
{
	t_input				*next;
	t_input				*prev;
	t_string			*str;
	t_return			prompt_type;
	size_t				prompt_len;
	unsigned short		offset_col;
	struct winsize		*ts;
	t_cpos				cpos;
	t_select_pos		select_pos;
	BOOL				lock;
};

/*
** @brief TODO
**
** @arg TODO
*/

typedef struct s_window	t_window;
struct					s_window
{
	t_input				*cur_head;
	t_input				*cur;
	t_input				*save;
	ssize_t				h_lvl;
	BOOL				h_complet;
	struct winsize		ts;
	int					cmd_ret;
	t_select			select;
};

/*
** @file       input.c
**
** @brief      Main functions to read the input
*/

char					*sh_get_line(t_input *input, t_sh_opt *opts);
t_input					*input_new(void);
t_input					*input_add_new(t_input *input);
t_input					*input_hard_reset(t_input **input);

/*
** @file       input_utils.c
**
** @brief      Utility functions used by the input
*/

void					reset_input(t_input *input) __attribute__ ((deprecated("use input_reset instead")));
size_t					pos_in_str(t_input *input);
void					input_destroy(t_input **input);
void					input_reset(t_input *input);
t_input					*input_get_writable(t_input *input);

/*
** @file       history_input_utils.c
**
** @brief      Utility functions used by the history input
*/

t_input					*input_from_history(const char *hist);

/*
** @file input_move.c
**
** @brief Functions used to move in the input
*/
t_cpos					input_get_first_pos(t_input *input);
t_cpos					input_get_last_pos(t_input *input);
t_input					*input_back_to_origin(t_input *input);
t_input					*input_back_to_writable(t_input *input);
void					input_goto_line_end(t_input *input);

/*
** @file        input_utils_2.c
**
** @brief       Utility functions used by the input
*/

void					input_to_save(t_input **to_save, t_input *new_inp);
t_input					*input_from_save(t_input **to_destroy);
int						count_nb_input(t_input *input);
t_input					*input_get_last(t_input *input);


/*
** @file input_windows.c
**
** @brief Functions used to get window info
*/
t_window				*get_windows(int rst);
t_input					*goto_input(t_input *input, t_input *dest_inp);

/*
** @file input_get.c
**
** @brief Functions used to get the input
*/

int						*get_cmd_ret(void);
t_select				*get_select(void);
struct winsize			*get_ts(void);
t_input					*input_get_cur_head(void);
t_input					*input_get_cur(void);

/*
** @file input_draw.c
**
** @brief functions used to draw the input
*/

void					draw_char(t_input *input, char *c);
void					redraw_input(t_input *inp);
t_input					*input_draw(t_input *input);

#endif
