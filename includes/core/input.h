/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/12 15:25:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include <string/ft_string.h>
# include <libtcaps.h>
# include <core/prompt.h>
# include <sys/ioctl.h>
//int		sh_get_command(t_ms_data	*data);

typedef struct s_select	t_select;
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
	t_string		*str;
	size_t			prompt_len;
	size_t			offset_col;
	size_t			offset_line;
	struct winsize	ts;
	t_cpos			cpos;
	t_select		select;
};

/**
** @file       input.c
**
** @brief      Functions to read the input
*/
char	*sh_get_line(t_sh_opt *opts);
char	*sh_get_line2(void);
void	reset_input(t_input *input);
size_t	pos_in_str(t_input input);

extern	t_input	*g_input;

#endif
