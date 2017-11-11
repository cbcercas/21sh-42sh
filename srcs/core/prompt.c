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
#include <environ/getter_env.h>
#include <environ/builtin_env_utils.h>
#include <ftprintf.h>
#include <core/input.h>
#include <core/tcaps.h>
#include <ft_libgen.h>

//TODO see todo g_ret
#include <core/prompt.h>
#include <core/return.h>
#include <tools/tools.h>

static size_t		get_prompt(void)
{
	char		*user;
	char		*path;
	const char	*basename;
	char		*retstr;
	size_t		len;

	user = get_var_value(get_envs(), "USER");
	if (!user)
		user =  "???";
	path = get_pwd();//TODO use get_pwd, after merge whith exec
	basename = ft_basename(path);
	retstr = (!g_ret) ? "\033[32m^_^" : "\033[91mX_X";
	ft_printf("\033[0m(%s\033[0m) - %s - %s $ ",
			  retstr, user, basename);
	len = 11 + 3 + ft_strlen(user) + ft_strlen(basename);
	ft_strdel(&path);
	return (len);
}

void		prompt_normal(t_input *inp)
{
	inp->prompt_type = E_RET_NEW_PROMPT;
	inp->prompt_len = get_prompt();
	inp->offset_col = (unsigned short)inp->prompt_len % inp->ts->ws_col;
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
	inp->offset_col = (unsigned short)inp->prompt_len % inp->ts->ws_col;
	inp->cpos.cp_col = inp->offset_col;
	inp->cpos.cp_line = 0;
}

void sh_print_prompt(t_input *input, const char *prompt, t_return ret)
{
	/*if (get_curs_x() > 1)
	{
		tputs(tgetstr("mr", NULL), 1, ft_putchar2);
		ft_putendl("%");
		tputs(tgetstr("me", NULL), 1, ft_putchar2);
	}*/

	if ((input->prev == NULL && ret == E_RET_NEW_PROMPT) || (ret == E_RET_REDRAW_PROMPT && input->prompt_type == E_RET_NEW_PROMPT))
		prompt_normal(input);
	else //if ((ret != E_RET_EMPTY_LINE && ret != E_RET_NEW_PROMPT) && (ret == E_RET_REDRAW_PROMPT && input->prompt_type != E_RET_NEW_PROMPT))
		prompt_perso(input, prompt, ret);
}

