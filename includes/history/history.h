/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:56:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 12:46:32 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <types/bool.h>
# include <array/array.h>
# include <core/input.h>

# define HISTORY_FILE ".21sh_history"

typedef	struct	s_hist
{
	const char		*cmd;
	char					*buf;
	int						cur;
	BOOL					session;
	struct s_hist	*next;
}								t_hist;

t_hist					*sh_history_new(char *cmd);
t_array					*sh_history_get(void);
char	*history_get_path(char *str);
t_array					*sh_history_init(void);
void 						sh_history_print(void);
void 						sh_history_print_in_log(void);
void						sh_history_save(void);
t_hist					*sh_history_set_new(char const *cmd);
int							sh_history_is_space_plus(char const *line);
void						sh_history_up(t_input *input);
void						sh_history_down(t_input *input);
void 						sh_history_del(void *h);
void 						sh_history_insert_buf(char *str);
void						sh_history_draw_line(t_input *input, const char *line);
void					history_research_prompt(char *buff, char *result, BOOL fail);
void					history_research_exit(char *result, char *line, BOOL fail, t_input *input);
void					history_mess_quit(int sig);
void					sh_history_clear_line(unsigned int nb_of_car);
void					history_research(t_input *input);
void					history_research_start(char **line, char **result, BOOL *fail);
void					sh_history_clear_len(char *buff, char *result, BOOL fail);
void 					sh_history_destroy(void);
void					sh_history_var_session_reset(void);
//BOOL       		sh_history_is_print(char const *line);
const char					*sh_history_get_search(const char *line);
const char					*sh_history_get_at(ssize_t nb);

#endif
