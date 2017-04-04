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

t_bool	gr_list(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_list.");
	if (((gr_separator_op(tokens, where) == true) && \
	(gr_and_or(tokens, where) == true)) || \
	(gr_and_or(tokens, where) == true) || \
	(gr_separator_op(tokens, where) == true))
	{
		log_dbg2("Parser returned true at gr_list.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_list.");
		return (false);
	}
}

t_bool	gr_separator(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_separator.");
	if ((gr_separator_op(tokens, where) == true) && \
	(gr_linebreak(tokens, where) == true))
	{
		log_dbg2("Parser returned true at gr_separator.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_separator.");
		return (false);
	}
}

t_bool	gr_linebreak(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_linebreak.");
	if (gr_newline_list(tokens, where) == true)
	{
		log_dbg2("Parser returned true at gr_linebreak.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_linebreak.");
		return (false);
	}
}

t_bool	gr_newline_list(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_newline_list.");
	if (tok->type == E_TOKEN_SEMI)
	{
		log_dbg2("Parser returned true at gr_newline_list.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_newline_list.");
		return (false);
	}
}

t_bool	gr_and_or(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_and_or.");
	if ((gr_pipeline(tokens, where) == true) || \
	((gr_check_and_if(tokens, where) == true) && \
	(gr_linebreak(tokens, where) == true) && \
	(gr_pipeline(tokens, where) == true)) || \
	(gr_check_or_if(tokens, where) == true) && \
	(gr_linebreak(tokens, where) == true) && \
	(gr_pipeline(tokens, where) == true))
	{
		log_dbg2("Parser returned true at gr_and_or.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_and_or.");
		return (false);
	}
}
