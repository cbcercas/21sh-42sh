/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:30:33 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/09 16:19:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

static char	*autocomplete_disp_one(t_string *string)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!string || !string->s)
		return ("");
	if (!ft_strchr(string->s, '/'))
		return (string->s);
	ret = string->s;
	while (string->s[i] && i < string->len - 2)
	{
		if (string->s[i] == '/')
			ret = &string->s[i + 1];
		i++;
	}
	return (ret);
}

void		autocomplete_display(t_array *content)
{
	size_t		i;
	t_string	*tmp;

	if (!content || !content->used || content->used == 1)
		return ;
	i = 0;
	default_terminal_mode();
	ft_putstr("\n");
	if (content->used > 42)
		ft_printf("%s: too many possibilities (%d possibilities)", PROGNAME,\
				content->used);
	while (content->used <= 42 && i < content->used)
	{
		tmp = (t_string *)array_get_at(content, i);
		if (tmp && tmp->s)
			ft_printf(" %s ", autocomplete_disp_one(tmp));
		i++;
	}
	ft_printf("\n");
	autocomplete_display_prompt(g_input);
	raw_terminal_mode();
}

void		autocomplete_display_prompt(t_input *input)
{
	size_t	pos;

	pos = 0;
	pos = pos_in_str(*input);
	input->offset_col = sh_len_prompt();
	input->offset_line = 0;
	input->cpos.cp_line = 0;
	input->select.is = false;
	input->cpos.cp_col = (unsigned short)input->offset_col;
	sh_print_prompt();
	redraw_line(input);
	while (pos != pos_in_str(*input))
		exec_arrow_right(NULL, input);
}

void		autocomplete_display_line(t_input *input, int len)
{
	tputs(tgetstr("cr", NULL), 1, ft_putchar2);
	autocomplete_display_prompt(input);
	while (len--)
		exec_arrow_right(NULL, input);
}
