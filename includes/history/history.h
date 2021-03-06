/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:56:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 13:44:43 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <array/array.h>
# include <logger.h>
# include <ftprintf.h>
# include <fcntl.h>
# include <secure_memory/secure_memory.h>
# include <environ/env_utils.h>
# include <environ/getter_env.h>
# include <core/input.h>
# include <core/tcaps.h>

# define HISTORY_FILE ".42sh_history"
# define HISTORY_FILE_MAX 10000
# define HISTORY_MAX 500

/*
** @file   history.h
**
** @brief  Function prototypes for the history module
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @struct s_hist
**
** @brief Contains all the info on each history entries
**
** @param cmd The command stored
** @param cur The position of this command in the history
** @param session If set to false, the cmd has been loaded from a file. If set
** to true, the command has been added in the history from the current instance
** of the program
** @param next Is a pointer to the next history entry
*/

typedef	struct		s_hist
{
	const char		*cmd;
	ssize_t			cur;
	BOOL			session;
	struct s_hist	*next;
}					t_hist;

/*
** @file history.c
**
** @brief Main functions for the history module
*/

t_array				*sh_history_get(void);
char				*history_get_path(char *str);
void				sh_history_save(void);
const char			*history_get_n(size_t n);

/*
** @file history_arrow.c
**
** @brief Functions used to handle the arrows for the history module
*/

t_input				*sh_history_up(t_input *input);
t_input				*sh_history_down(t_input *input);
void				sh_history_draw_line(t_input *input, const char *line);
void				sh_history_clear_len(char *buff, char *result, BOOL fail);

/*
** @file history_init.c
**
** @brief Functions to initialize the history module
*/

t_array				*sh_history_init(t_array *hists);
int					sh_history_init_one(t_array *hists, int fd);
int					get_history_init_choice(int choice);

/*
** @file history_print.c
**
** @brief Functions to print the history
*/

void				sh_history_print(void);
void				sh_history_print_in_log(void);

/*
** @file history_getter.c
**
** @brief Functions to get and parse the history
*/

t_hist				*sh_history_set_new(char **cmd);
int					sh_history_is_space_plus(char const *line);
const char			*sh_history_get_search(const char *line);
const char			*sh_history_get_at(ssize_t nb);

/*
** @file history_research.c
**
** @brief Functions to search the history
*/

void				history_research_prompt(char *buff, t_input *result,
											BOOL fail, BOOL del);
void				history_research(t_input *input);

/*
** @file history_research_start_end.c
**
** @brief Functions to research in the history from start or end
*/

void				history_research_exit(t_input *result, char *line,
																t_input *input);
void				history_research_start(char **line, t_input **result,
																	BOOL *fail);

/*
** @file history_list_utils.c
**
** @brief Utility functions used by the lists.
*/

t_hist				*sh_history_new(char *cmd);
void				sh_history_insert_buf(char *str);
void				sh_history_destroy(void);
void				sh_history_var_session_reset(void);
void				sh_history_del(void *i);
void				*sh_history_remove_at(size_t nb);

/*
** @file history_input_utils.c
**
** @brief Functions used to hande the input for history
*/

char				*input_to_history(t_input *input);
t_input				*input_from_history(const char *hist);

/*
** @file history_getter_2.c
**
** @brief Contains functions to help get the history
*/

const char			*history_get_next(char *str);
const char			*history_get_prev(char *str);
#endif
