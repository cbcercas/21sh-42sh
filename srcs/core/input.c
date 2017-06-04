/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:12 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/04 20:19:24 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>
#include <sys/ioctl.h>

BOOL remove_escaped_newline(char **input)
{
	size_t	len;

	len = ft_strlen(*input);
	if (*(*input + len - 1) == '\\')
	{
		*(*input + len - 1) = '\0';
		return true;
	}
	return (false);
}

/**
** @brief      Read the input on standard entry
**
** @return     A pointer to the input string
*/
char	*sh_get_line_old(void)
{
	char	*line;
	char	*input;
	input = NULL;
	(void)get_next_line(0, &line);
	input = ft_strjoincl(input, line, 3);
	while (remove_escaped_newline(&input))
	{
		ft_printf(">");
		(void)get_next_line(0, &line);
		input = ft_strjoincl(input, line, 3);
	}
	if (*input != '\0')
		return (input);
	ft_strdel(&input);
	return (NULL);
}

void	tcaps_down(t_input *input)
{
	// Descend une ligne
	tputs(tgetstr("do", NULL), 1, ft_putchar2);
	input->offset_line += 1;
	input->cpos.cp_line += 1;
	// goto debut ligne
	tputs(tgetstr("cr", NULL), 1, ft_putchar2);
	input->cpos.cp_col = 0;
}

static void	tcaps_insert_char(char *c)
{
	tputs(tgetstr("im", NULL), 0, &ft_putchar2);
	tputs(c, 1, &ft_putchar2);
	tputs(tgetstr("ie", NULL), 0, &ft_putchar2);
}

static void	draw_char(t_input *input, char *c)
{
	// si je suis au milieu de la string j'insert le char sinon je le write
	if (input->str->len > (((((input->ts.ts_cols * input->offset_line) - input->offset_col)
		+ (input->cpos.cp_col - 1 + input->offset_line )))))
		tcaps_insert_char(c);
	else
		tputs(c, 1, &ft_putchar2);
	input->cpos.cp_col += 1;
	if (input->cpos.cp_col >= input->ts.ts_cols)
		tcaps_down(input);
	// si je suis au milieu de la string je la redraw
	if (input->str->len > ((((input->ts.ts_cols * input->offset_line) + input->cpos.cp_col) - input->offset_col)))
		redraw_line(input);
}

char	*sh_get_line(void)
{
	char		buff[MAX_KEY_STRING_LEN];
	ssize_t		res;
	t_key		key;
	BOOL		stop;
	static t_input	input;

	ft_bzero(&input, sizeof(input));
	stop = false;
	raw_terminal_mode();
	reset_input(&input);
	while (stop == false)
	{
		ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
		res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN);
		buff[res] = '\0';
		key = key_get(buff);
		if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key, &input);
		else
		{
			if (!string_insert(input.str, key.key,
		(((((input.ts.ts_cols * input.offset_line - (input.offset_line ? 1 : 0)) - input.offset_col )
				+ (input.cpos.cp_col + input.offset_line))))))
				return (NULL);
			sh_history_insert_buf(input.str->s);
			draw_char(&input, key.key);
		}
		key_del(&key);
	}
	default_terminal_mode();
	sh_history_insert_buf(NULL);
	return (input.str->len > 0 ? ft_strdup(input.str->s) : NULL);
}
