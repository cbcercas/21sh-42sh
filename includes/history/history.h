/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:56:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/29 16:39:18 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <logger.h>
# include <libft.h>
# include <gnl/get_next_line.h>
# include <ftprintf.h>
# include <core/input.h>
# include <core/tcaps.h>
# include <core/prompt.h>
# include <types/bool.h>
# include <signals/signals.h>

# define ISBLANC(x) (x == '\t' || x== '\v' || x == ' ')
# define ISIMPRC(x) (x[0] > 31 && x[0] < 127 && x[1] == 0)
# define ISCTRL(x) ((x[0] >= 1 && x[0] <= 26) && x[1] == 0)
# define ISCTRLR(x) (x[0] == 18 && x[1] == 0)
# define ISARR(x) (x[0] == 27 && x[1] == 91 && x[4] == 0)
# define HISTORY_FILE "/tmp/.21sh_history"

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
int 						sh_history_open_fd(char *path, int flag);
t_array					*sh_history_init(char *path);
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
int						sh_history_is_print(char const *line);
const char					*sh_history_get_search(const char *line);
const char					*sh_history_get_at(size_t nb);

#endif
