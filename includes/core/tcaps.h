/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:02:09 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/21 08:35:59 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCAPS_H
# define TCAPS_H

# include <libtcaps.h>
# include <core/init.h>
# include <history/history.h>
# include <core/prompt.h>
# include <autocomplete/autocomplete.h>

/*
** @file   tcaps.h
**
** @brief  Function prototypes for the tcaps TODO: The rest of it
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @struct s_key_exec
**
** @brief Struct containing info about a key and its function to be executed
**
** @param key_code Key code corresponding to the key pressed
** @param f The function to be executed
*/

typedef struct	s_key_exec
{
	char		*key_code;
	BOOL		(*f)(const t_key *, t_input *input);
}				t_key_exec;

/*
** @file term_modes.c
**
** @brief Contains the term_modes functions
*/

void			raw_terminal_mode(void);
void			default_terminal_mode(void);

/*
** @file tcaps_key_exec.c
**
** @brief Contains the function that executes the keys when pressed
*/

BOOL			key_exec(t_key *key, t_input *input);

/*
** @file tcaps_exec_ctrl_1.c
**
** @brief Contains the ctrl functions to be executed
*/

BOOL			exec_ctrl_c(const t_key *key, t_input *input) __attribute__
((deprecated("Todo refactor new input design")));
BOOL			exec_ctrl_d(const t_key *key, t_input *input) __attribute__
((deprecated("Todo refactor new input design")));
BOOL			exec_ctrl_z(const t_key *key, t_input *input);
BOOL			exec_ctrl_a(const t_key *key, t_input *input) __attribute__
((deprecated("Todo refactor new input design")));
BOOL			exec_ctrl_e(const t_key *key, t_input *input) __attribute__
((deprecated("Todo refactor new input design")));
BOOL			exec_ctrl_l(const t_key *key, t_input *input);

/*
** @file tcaps_exec_ctrl_2.c
**
** @brief Contains the ctrl functions to be executed
*/

BOOL			exec_ctrl_j(const t_key *key, t_input *input);
BOOL			exec_ctrl_r(const t_key *key, t_input *input);

/*
** @file tcaps_exec_ctrl_select.c
**
** @brief Contains the ctrl functions to be executed in autocomplet mode
*/

BOOL			exec_ctrl_j_select(t_input *input);


/*
** @file tcaps_exec_backspace.c
**
** @brief Contains the backspace functions to be executed
*/

BOOL			exec_backspace(const t_key *key, t_input *input);

/*
** @file tcaps_exec_delete.c
**
** @brief Contains the delete functions to be executed
*/

BOOL			exec_delete(const t_key *key, t_input *input);

/*
** @file tcaps_exec_tab.c
**
** @brief Contains the tab functions to be executed
*/

BOOL			exec_tab(const t_key *key, t_input *input);

/*
** @file tcaps_exec_arrow.c
**
** @brief Contains the arrow functions to be executed
*/

BOOL			exec_arrow_right(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));
BOOL			exec_arrow_left(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));
BOOL			exec_arrow_up(const t_key *key, t_input *input);
BOOL			exec_arrow_down(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));

/*
** @file tcaps_exec_arrow_select.c
**
** @brief Contains the arrow functions to be executed for normal mode
*/

BOOL			exec_arrow_right_normal(t_input *input);
BOOL			exec_arrow_left_normal(t_input *input);

/*
** @file tcaps_exec_arrow_select.c
**
** @brief Contains the arrow functions to be executed for autocompletion mode
*/

BOOL			exec_arrow_right_select(t_sel_data *data);
BOOL			exec_arrow_left_select(t_sel_data *data);
BOOL			exec_arrow_up_select(t_sel_data *data);
BOOL			exec_arrow_down_select(t_sel_data *data);


/*
** @file tcaps_exec_escape.c
**
** @brief Contains the escape functions to be executed
*/

BOOL 			exec_escape(const t_key *key, t_input *input);

/*
** @file tcaps_exec_escape.c
**
** @brief Contains the escape functions to be executed when in autocomplet mode
*/

BOOL			exec_escape_select(void);


/*
** @file tcaps_exec_alt_arrows.c
**
** @brief Contains the alt arrow functions to be executed
*/

BOOL			exec_alt_up(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));
BOOL			exec_alt_down(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));
BOOL			exec_alt_left(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));
BOOL			exec_alt_right(const t_key *key, t_input *input)__attribute__
							((deprecated("Todo refactor new input design")));

/*
** @file tcaps_exec_end_home.c
**
** @brief Contains the end/home functions to be executed
*/

BOOL			exec_end(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));
BOOL			exec_start(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));

/*
** @file tcaps_exec_select.c
**
** @brief Contains the select functions to be executed
*/

BOOL			exec_insert(const t_key *key, t_input *input) __attribute__
							((deprecated("Todo refactor new input design")));
void			exec_insert_off(t_input *input);
//void			draw_reverse_char(char c, BOOL is_reverse);
BOOL			exec_insert_arrows(const t_key *key, t_input *input)
				__attribute__ ((deprecated("Todo refactor new input design")));
void			reset_insert_pos(void);

/*
** @file tcaps_exec_alt_c.c
**
** @brief Contains the functions to be executed
*/

BOOL			exec_alt_c(const t_key *key, t_input *input);

/*
** @file tcaps_exec_alt_v.c
**
** @brief Contains the functions to be executed
*/

BOOL			exec_alt_v(const t_key *key, t_input *input);

//BOOL			exec_alt_x(const t_key *key, t_input *input);

/*
** @file tcaps_redraw_line.c
**
** @brief Contains the redraw line functions
*/

void			redraw_line(t_input *input) __attribute__
									((deprecated("Use redraw_input instead")));
void			reset_line(t_input *input) __attribute__
										((deprecated("Refactor or remove")));

//void			tcaps_down(t_input *input);

/*
** @file clean_term.c
**
** @brief Contains the functions to be executed
*/

void			clean_term(void);

/*
** @file get_curs_y.c
**
** @brief Contains the functions to be executed
*/

int				get_curs_y(void);

/*
** @file get_curs_x.c
**
** @brief Contains the functions to be executed
*/

int				get_curs_x(void);

#endif
