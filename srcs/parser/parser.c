/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:43:16 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/21 10:25:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

/*
** @brief Initializes the parser for the program
**
** @param tokens  The tokens sent by the lexer
** @return Returns true if parsing ok and false if error + printf error
** in stdout and log fatal
*/

static void	dbg_printtok_str(t_array *tokens, size_t i)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, i);
	lexer_print_token(tok);
	ft_putstr(": ");
	ft_putnstr(tok->str, tok->len);
	ft_putchar('\n');
}

t_bool		gr_complete_cmd(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_complete_cmd.");
	if ((gr_list(tokens, where) == true) || \
	(gr_list(tokens, where) == true && \
	gr_separator(tokens, where) == true))
	{
		log_dbg2("Parser returned true at gr_complete_cmd.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_complete_cmd.");
		return (false);
	}
}

t_bool		parser_parse(t_array *tokens)
{
	size_t i;
	t_bool ok;

	i = 0;
	ok = false;
	while (i < tokens->used)
	{
		dbg_printtok_str(tokens, i);
		if (gr_complete_cmd(tokens, i) == true)
			ok = true;
		else
			ok = false;
		i++;
	}
	if (ok == false)
	{
		ft_printf("\nParser error\n");
		log_fatal("\nParser error\n");
	}
	return (ok);
}

/*
** TODO, make the grammar functions print the errors !
*/
