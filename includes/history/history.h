/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:56:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/03 18:16:01 by gpouyat          ###   ########.fr       */
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

# define ISBLANC(x) (x == '\t' || x== '\v' || x == ' ')

typedef	struct	s_hist
{
	char					*cmd;
	char					*buf;
	size_t				*cur;
	struct s_hist	*next;
}								t_hist;

t_hist					*sh_history_new(char *cmd);
t_array					*sh_history_get(void);
int 						sh_history_open_fd(void);
t_array					*sh_history_init(void);
void 						sh_history_print();
void 						sh_history_print_in_log(void);
void						sh_history_save(void);
t_hist	*sh_history_set_new(char const *cmd);
int			sh_history_is_space_plus(char const *line);


#endif
