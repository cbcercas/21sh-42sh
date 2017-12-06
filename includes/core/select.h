/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 23:09:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/30 23:11:49 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <libtcaps.h>
# include <string/ft_string.h>

# define USHRT unsigned short

typedef struct s_sel_opt		t_sel_opt;

struct							s_sel_opt
{
	int							selectable;
	BOOL						color;
};

typedef struct s_sel_display	t_sel_display;


typedef struct s_sel_word		t_sel_word;
struct							s_sel_word
{
	struct s_sel_word			*next;
	struct s_sel_word			*prev;
	const char					*word;
	mode_t 						st_mode;
	size_t						len;
	size_t						num;
	BOOL						select;
	BOOL						cursor;
};

struct							s_sel_display
{
	t_cpos						cpos;
	unsigned short				col_size;
	unsigned short				col_num;
	size_t 						word_num;
	t_sel_word					*first;
	struct winsize				ts;
	BOOL						fixed_scroll;
};

typedef struct s_sel_data		t_sel_data;

struct							s_sel_data
{
	t_sel_opt					options;
	t_sel_display				disp;
	t_array						*array;
	t_sel_word					*words;
	size_t 						cur_word;
	BOOL						active;
};

t_sel_data		*select_get_data(void);

void			select_select(int selectable, BOOL color, t_array *arr,
							  char *current);
void *select_init(t_sel_data *data, t_array *argv, char *cur_word);
void			select_init_opt(int selectable, BOOL color);
void			select_deinit(t_sel_data **data);
void			*select_exit(const char *fmt, ...);

/*
 * Display
 */
void		*dsp_init(void);
void		dsp_reinit(void);
void		display_word(t_sel_word *word, t_sel_display *dsp);
void		display_list(t_sel_word *lst, t_sel_display *dsp);
void		display_line(t_sel_word *lst, t_sel_display *dsp);
void		display_blank_line(struct winsize *ts);

BOOL		word_is_on_screen(t_sel_display *disp, t_sel_word *word);
void		display_print_word(t_sel_word *word);

/*
 * Word list
 */

t_sel_word			*word_list_create(t_array *words);
t_sel_word			*word_list_destroy(t_sel_word **list);

t_sel_word			*word_get_current(void);
t_sel_word			*word_get_num(size_t num);
void				word_renum(t_sel_word *list);

void				word_print_list(t_sel_word *list);

#endif
