/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:30:33 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/21 16:47:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>


static char *aff_one(t_string *string)
{
	char 		*ret;
	size_t	i;

	i = 0;
	if (!string || !string->s)
		return("");
	if (!ft_strchr(string->s, '/'))
		return (string->s);
	ret = string->s;
	while(string->s[i] && i < string->len - 2)
	{
		if (string->s[i] == '/')
			ret = &string->s[i + 1];
		i++;
	}

	return (ret);
}

static void input_zero(void)
{
	g_input->offset_line = 0;
	g_input->cpos.cp_line = 0;
	g_input->select.is = false;
	g_input->cpos.cp_col = (unsigned short)g_input->offset_col;
}

static void re_display_input(size_t pos)
{
	ft_putstr("\n");
	sh_print_prompt();
	redraw_line(g_input);
	while (pos != pos_in_str(*g_input))
		exec_arrow_right(NULL, g_input);
}

void aff(t_array *content)
{
	size_t 		i;
	t_string 	*tmp;
	size_t 	pos;

	if (!content || !content->used)
		return ;
	pos = pos_in_str(*g_input);
	input_zero();
	i = 0;
	default_terminal_mode();
	ft_putstr("\n");
	if (content->used > 42)
		ft_printf("%s: too many possibilities (%d)", PROGNAME ,content->used);
	while( content->used <= 42 && i < content->used)
	{
		tmp = (t_string *)array_get_at(content, i);
		if (tmp && tmp->s)
			ft_printf(" %s ", aff_one(tmp));
		i++;
	}
	re_display_input(pos);
	raw_terminal_mode();
}
