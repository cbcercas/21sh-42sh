/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:02:09 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/30 14:29:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCAPS_H
# define TCAPS_H

# include <libft.h>
# include <libtcaps.h>
# include <types/bool.h>
# include <core/input.h>
# include <logger.h>

typedef struct	s_key_exec
{
	char	*key_code;
	BOOL	(*f)(const t_key *, t_input *input);
}				t_key_exec;

void	raw_terminal_mode(void);
void	default_terminal_mode(void);

BOOL	key_exec(t_key *key, t_input *input);

BOOL	exec_ctrl_c(const t_key *key, t_input *input);
BOOL	exec_ctrl_d(const t_key *key, t_input *input);
BOOL	exec_ctrl_z(const t_key *key, t_input *input);
BOOL	exec_ctrl_a(const t_key *key, t_input *input);
BOOL	exec_ctrl_e(const t_key *key, t_input *input);
BOOL	exec_ctrl_l(const t_key *key, t_input *input);
BOOL	exec_ctrl_j(const t_key *key, t_input *input);

BOOL	exec_backspace(const t_key *key, t_input *input);
BOOL	exec_delete(const t_key *key, t_input *input);

BOOL	exec_tab(const t_key *key, t_input *input);

BOOL	exec_arrow_right(const t_key *key, t_input *input);
BOOL	exec_arrow_left(const t_key *key, t_input *input);
BOOL	exec_arrow_up(const t_key *key, t_input *input);
BOOL	exec_arrow_down(const t_key *key, t_input *input);

void	redraw_line(t_input *input);
void	tcaps_down(t_input *input);

#endif