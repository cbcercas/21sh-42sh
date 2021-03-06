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
#include <environ/env_utils.h>
#include <ftprintf.h>
#include <core/input.h>
#include <core/tcaps.h>
#include <ft_libgen.h>

/*
** @brief Prints the prompt
**
** @return Returns the size of the prompt
*/

static size_t		get_prompt(void)
{
	char		*user;
	char		*path;
	const char	*basename;
	char		*retstr;
	size_t		len;

	user = get_var_value(get_envs(), "USER");
	if (!user)
		user = "???";
	if (!(path = get_pwd()))
		path = "???";
	basename = ft_basename(path);
	if (get_data(NULL)->opts.color)
		retstr = (!*get_cmd_ret()) ? "\033[32m^_^" : "\033[91mX_X";
	else
		retstr = (!*get_cmd_ret()) ? "^_^" : "X_X";
	ft_dprintf(STDIN_FILENO, "\033[0m(%s\033[0m) - %s - %s $ ",
			retstr, user, basename);
	len = 11 + 3 + ft_strlen(user) + ft_strlen(basename);
	if (*path != '?')
		ft_strdel(&path);
	return (len);
}

/*
** @brief Prints the prompt and sets the variables
**
** @param inp current input
*/

void				prompt_normal(t_input *inp)
{
	inp->prompt_type = E_RET_NEW_PROMPT;
	inp->prompt_len = get_prompt();
	inp->offset_col = (unsigned short)inp->prompt_len % inp->ts->ws_col;
	if (!inp->offset_col)
	{
		inp->offset_col++;
		ft_putstr_fd(" ", STDIN_FILENO);
	}
	inp->cpos.cp_col = inp->offset_col;
	inp->cpos.cp_line = 0;
}

/*
** @brief display not useally prompt
**
** @param inp current input
** @param prompt the personalized prompt
** @param ret the ret of the last command
*/

void				prompt_perso(t_input *inp, const char *prompt, t_return ret)
{
	static char		p[E_RET_LEXER_PIPE - E_RET_LEXER_INCOMPLETE + 1][8] =
	{{""}, {"quote"}, {"bquote"}, {"dquote"}, {""}};

	if (ret == E_RET_REDRAW_PROMPT)
		ret = inp->prompt_type;
	if (prompt == NULL)
		prompt = p[ret - E_RET_LEXER_INCOMPLETE];
	ft_dprintf(STDIN_FILENO, "%s> ", prompt);
	inp->prompt_len = ft_strlen(prompt) + 2;
	inp->offset_col = (unsigned short)inp->prompt_len % inp->ts->ws_col;
	if (!inp->offset_col)
	{
		inp->offset_col++;
		ft_putstr_fd(" ", STDIN_FILENO);
	}
	inp->cpos.cp_col = inp->offset_col;
	inp->cpos.cp_line = 0;
}

/*
** @brief Calls the other functions to print the prompt and set the
** approriate variables
**
** @param input The current input
** @param prompt The prompt string
** @param ret The last ret value
*/

void				sh_print_prompt(t_input *input, const char *prompt,
									t_return ret)
{
	if ((input->prev == NULL && ret == E_RET_NEW_PROMPT) ||
			(ret == E_RET_REDRAW_PROMPT &&
					(input->prompt_type == E_RET_NEW_PROMPT ||
													input->prompt_type == 0)))
		prompt_normal(input);
	else
		prompt_perso(input, prompt, ret);
}
