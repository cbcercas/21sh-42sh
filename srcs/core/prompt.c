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
#include <core/return.h>

size_t		get_prompt(BOOL print)
{
	char		*path;
	char		*tmp;
	size_t		len;
	char		*ret;

	path = NULL;
	ret = (!g_ret ? "\033[92m" : "\033[91m"); // TODO g_ret really need a global
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
	ft_printf("Un joli prompt $ ");
	inp->prompt_type = E_RET_NEW_PROMPT;
	inp->prompt_len = 17;
	inp->offset_col = 17;
	//TODO offset if prompt > ts
	inp->cpos.cp_col = inp->offset_col;
	inp->cpos.cp_line = 0;
}

void 		prompt_perso(t_input *inp, const char *prompt, t_return ret)
{
	static char p[E_RET_LEXER_PIPE - E_RET_LEXER_INCOMPLETE + 1][8]=
					{{""}, {"quote"}, {"bquote"}, {"dquote"}, {""}};

	if (ret == E_RET_REDRAW_PROMPT)
		ret = inp->prompt_type;
	if (prompt == NULL)
			prompt = p[ret - E_RET_LEXER_INCOMPLETE];
	ft_printf("%s> ", prompt);
	inp->prompt_type = ret;
	inp->prompt_len = ft_strlen(prompt) + 2;
	//TODO offset if prompt > ts
	inp->offset_col = (unsigned short)inp->prompt_len;
	inp->cpos.cp_col = inp->offset_col;
	inp->cpos.cp_line = 0;
}

void sh_print_prompt(t_input *input, const char *prompt, t_return ret)
{
	if (get_curs_x() > 1)
	{
		tputs(tgetstr("mr", NULL), 1, ft_putchar2);
		ft_putendl("%");
		tputs(tgetstr("me", NULL), 1, ft_putchar2);
	}

	if ((input->prev == NULL && ret == E_RET_NEW_PROMPT) || (ret == E_RET_REDRAW_PROMPT && input->prompt_type == E_RET_NEW_PROMPT))
		prompt_normal(input);
	else //if ((ret != E_RET_EMPTY_LINE && ret != E_RET_NEW_PROMPT) && (ret == E_RET_REDRAW_PROMPT && input->prompt_type != E_RET_NEW_PROMPT))
		prompt_perso(input, prompt, ret);
}

