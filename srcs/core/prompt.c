/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:25:01 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/04 11:52:02 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <types/bool.h>
#include <environ/getter_env.h>
#include <environ/builtin_env_utils.h>
#include <ftprintf.h>
#include <core/input.h>
#include <core/tcaps.h>

//TODO see todo g_ret
#include <core/prompt.h>

size_t		get_prompt(BOOL print)
{
	char		*path;
	char		*tmp;
	size_t		len;
	char		*ret;

	path = NULL;
	ret = (!g_ret ? "\033[92m" : "\033[91m");
	tmp = get_var_value(get_envs(), "USER") ? get_var_value(get_envs(), "USER") : ("???");
	print ? ft_printf("\033[94m[%s] \033[0m", tmp) : 0;
	len = (ft_strlen(tmp) + 3);
	path = getcwd(path, 0);
	tmp = (path ? ft_strrchr(path, '/') : NULL);
	if (print && tmp && tmp[1])
		ft_printf("\033[93m➜ %s\033[0m %s🎩\033[0m  ", &tmp[1], ret);
	else if (print && tmp)
		ft_printf("\033[93m➜ %s\033[0m %s🎩\033[0m  ", tmp, ret);
	else if (print)
		ft_printf("\033[93m➜ \033[0m %s🎩\033[0m  ", ret);
	if (ft_strequ(tmp, "/"))
		len += 7;
	else
		len += (tmp ? ft_strlen(tmp) + 5 : 5);
	ft_strdel(&path);
	return (len);
}

void		prompt_normal(t_input *inp)
{
	reset_input(inp);
	ft_printf("Un joli prompt $ ");
	inp->prompt_len = 17;
	inp->offset_col = 17;
	inp->cpos.cp_col = inp->offset_col;
	inp->cpos.cp_line = 0;
}

void 		prompt_incomplete(t_input *inp)
{
	ft_printf("> ");
	//reset_input(inp);
	string_insert(inp->str,"\n", inp->str->len);
	inp->len_save = inp->str->len;
	inp->prompt_len = 2;
	inp->offset_col = 2;
	inp->cpos.cp_col = inp->offset_col;
	inp->cpos.cp_line = 0;
}

void		sh_print_prompt(void)
{
	if (get_curs_x() > 1)
	{
		tputs(tgetstr("mr", NULL), 1, ft_putchar2);
		ft_putendl("%");
		tputs(tgetstr("me", NULL), 1, ft_putchar2);
	}
	if (g_input->prompt)
	{
		prompt_normal(g_input);
	}
	else
	{
		prompt_incomplete(g_input);
	}

}

size_t		sh_len_prompt(void)
{
	return (g_input->prompt_len);
}
