/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:30:33 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/15 16:35:27 by gpouyat          ###   ########.fr       */
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

void aff(t_array *content)
{
	size_t 		i;
	t_string 	*tmp;

	i = 0;
	default_terminal_mode();
	clean_term();
	if (!content)
		return ;
	tputs(tgetstr("sc", NULL), 0, &ft_putchar2);
	ft_printf("\n");
	while( content->used <= 42 && i < content->used)
	{
		tmp = (t_string *)array_get_at(content, i);
		if (tmp && tmp->s)
			ft_printf(" %s ", aff_one(tmp));
		i++;
	}
	if (content->used > 42)
		ft_printf("%s: too many possibilities (%d)", PROGNAME ,content->used);
	raw_terminal_mode();
	tputs(tgetstr("rc", NULL), 0, &ft_putchar2);
}
