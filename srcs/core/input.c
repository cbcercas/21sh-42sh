/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 15:40:24 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>
#include <core/tcaps.h>
#include <tools/tools.h>
#include <history/history.h>

t_input *g_input;

BOOL			remove_escaped_newline(char **input)
{
	size_t	len;

	len = ft_strlen(*input);
	if (*(*input + len - 1) == '\\')
	{
		*(*input + len - 1) = '\0';
		return (true);
	}
	return (false);
}

/*
** @brief      Read the input on standard entry
**
** @return     A pointer to the input string
*/

/*
**char			*sh_get_line_old(void)
**{
**	char	*line;
**	char	*input;
**
**	input = NULL;
**	(void)get_next_line(0, &line);
**	input = ft_strjoincl(input, line, 3);
**	while (remove_escaped_newline(&input))
**	{
**		ft_printf(">");
**		(void)get_next_line(0, &line);
**		input = ft_strjoincl(input, line, 3);
**	}
**	if (*input != '\0')
**		return (input);
**	ft_strdel(&input);
**	return (NULL);
**}
*/

/*
**void			tcaps_down(t_input *input)
**{
**	tputs(tgetstr("do", NULL), 1, ft_putchar2);
**	input->offset_line += 1;
**	input->cpos.cp_line += 1;
**	tputs(tgetstr("cr", NULL), 1, ft_putchar2);
**	input->cpos.cp_col = 0;
**}
*/

/*
**"do" descends une ligne puis
**"cr" goto debut de ligne
*/

/*
**static void	tcaps_insert_char(char *c)
**  {
**  tputs(tgetstr("im", NULL), 0, &ft_putchar2);
**  tputs(c, 1, &ft_putchar2);
**  tputs(tgetstr("ie", NULL), 0, &ft_putchar2);
** }
*/

static void		draw_char(t_input *input, char *c)
{
	int		len;

	len = 0;
	if (c)
		len = ft_strlen(c);
	redraw_line(input);
	while (len--)
		exec_arrow_right(NULL, input);
}

/*
** si je suis au milieu de la string j'insert le char sinon je le write
**if (input->str->len > (((((input->ts.ws_col * input->offset_line) - \
**															input->offset_col)
**	  + (input->cpos.cp_col - 1 + input->offset_line )))))
**	  tcaps_insert_char(c);
**	  else
**	  tputs(c, 1, &ft_putchar2);
**	  input->cpos.cp_col += 1;
**	  if (input->cpos.cp_col >= input->ts.ws_col)
**	  tcaps_down(input);
**	// si je suis au milieu de la string je la redraw
**	if (input->str->len > ((((input->ts.ws_col * input->offset_line) + \
**									input->cpos.cp_col) - input->offset_col)))
**	redraw_line(input);
*/

t_input	*input_new(void)
{
	t_input	*input;

	if (!(input = ft_memalloc(sizeof(*input))))
		return (NULL);
	input->next = NULL;
	input->prev = NULL;
	input->ts = get_ts();
	input->select = get_select();
	input->hist_lock = false;
	input_reset(input);
	return (input);
}
t_input *input_hard_reset(t_input **input)
{
	input_destroy(input);
	*input = input_new();
	return (*input);
}

t_input	*input_get_cur_head(void)
{
	t_window	*w;

	w = get_windows(0);
	return (w->cur_head);
}

t_input	*input_get_cur(void)
{
	t_window	*w;

	w = get_windows(0);
	return (w->cur);
}

t_input *input_get_last(t_input *input)
{
	while (input && input->next)
		input = input->next;
	return (input);
}

t_input	*input_add_new(t_input *input)
{
	t_input	*save;

	if (!input)
		return (NULL);
	save = input->next;
	if((input->next = input_new()) == NULL)
		return (NULL);
	input->next->prev = input;
	input->next->next = save;
	if (save)
		save->prev = input->next;
	return (input->next);
}

char	*input_to_history(t_input *input)
{
	char	*line;

	line = NULL;
	if (input == NULL)
		return (NULL);
	while (input)
	{
		if(!(line = ft_strjoincl(line, input->str->s, 1)))
			return (NULL);
		if((input->next) && !(line = ft_strjoincl(line, "\\\n", 1)))
			return (NULL);
		input = input->next;
	}
	return (line);
}

t_input *input_from_history(const char *hist)
{
	t_input		*input;
	const char	*c;

	if (!(input = input_new()) || !hist)
		return (NULL);
	while ((c = ft_strstr(hist, "\\")) != NULL)
	{
		string_ninsert(input->str, hist, 0, hist - c);
		hist = c + 1;
		//TODO add support long line
		input = input_add_new(input);
	}
	string_ninsert(input->str, hist, 0, hist - c);
	while (input->prev)
		input = input->prev;
	return (input);
}

void	redraw_input(t_input *inp)
{
	t_input	*inpcpy;
	int 	line;

	inpcpy = inp;
	line = 0;
	//TODO prompt_len in history????
	tputs(tgoto(tgetstr("cm", NULL) , tgetnum("li"), (int)inp->prompt_len), 1, &ft_putchar2);
	//clear
	tputs(tgetstr("ce", NULL), 0, ft_putchar2);
	while (inpcpy)
	{
		//TODO check if line is multiline all char are drawed
		tputs(inpcpy->str->s, (int)inpcpy->str->len, &ft_putchar2);
		//TODO increment col pos, offset line...
		inpcpy = inpcpy->next;
		line += 1;
	}
	//TODO refactor to support multiline
	tputs(tgoto(tgetstr("cm", NULL) , tgetnum("li") - line, (int)inp->prompt_len + (int)inp->str->len), 1, &ft_putchar2);
}
/*

#define INPUT_PREV true
#define INPUT_NEXT false

t_input	*get_input_line(t_inputBOOL direction)
{
	if (direction == INPUT_PREV && (input->prev)
		if )

			else
}
(...);
*/



char *sh_get_line(t_input *input, t_sh_opt *opts)
{
	char			buff[MAX_KEY_STRING_LEN + 1];
	t_key			key;
	BOOL			stop;


	stop = false;
	raw_terminal_mode();
	//reset_input(&input);
	while (stop == false)
	{
		ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
		read(STDIN_FILENO, buff, (opts->tcaps) ? MAX_KEY_STRING_LEN : 1);
		key = key_get(buff, opts->tcaps);
		if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key, input);
		else if (is_printstr(buff) && !input->select->is)
		{
			if (!string_insert(input->str, key.key, pos_in_str(input)))
				return (NULL);
			//TODO Really reset hist lvl?
			get_windows(12);
			sh_history_insert_buf(input->str->s);
			draw_char(input, key.key);
		}
		input = get_windows(0)->cur;
		key_del(&key);
	}
	default_terminal_mode();
	input->hist_lock = true;
	sh_history_insert_buf(NULL);
	return (NULL);
}
