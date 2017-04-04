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

t_bool gr_simple_command(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_simple_command.");
	if (((gr_cmd_prefix(tokens, where) == true) && \
	(gr_cmd_word(tokens, where) == true) && \
	(gr_cmd_suffix(tokens, where) == true)) || \
	((gr_cmd_prefix(tokens, where) == true) && \
	(gr_cmd_word(tokens, where) == true)) || \
	((gr_cmd_prefix(tokens, where) == true)) || \
	(((gr_cmd_name(tokens, where) == true) && \
	(gr_cmd_suffix(tokens, where) == true))) || \
	(gr_cmd_name(tokens, where) == true))
	{
		log_dbg2("Parser returned true at gr_simple_command.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_simple_command.");
		return false;
	}
}

t_bool gr_cmd_prefix(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_cmd_prefix.");
	if (gr_io_redirect(tokens, where) == true)
	{
		log_dbg2("Parser returned true at gr_cmd_prefix.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_cmd_prefix.");
		return false;
	}
}

t_bool gr_cmd_word(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_cmd_word.");
	if (tok->type == E_TOKEN_WORD) //TODO, add check for pipe and stuff as for the rest
	{
		log_dbg2("Parser returned true at gr_cmd_word.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_cmd_word.");
		return false;
	}
}

t_bool gr_cmd_name(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_cmd_name.");
	if (tok->type == E_TOKEN_WORD) //TODO, add check for pipe and stuff as for the rest
	{
		log_dbg2("Parser returned true at gr_cmd_name.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_cmd_name.");
		return false;
	}
}

t_bool gr_cmd_suffix(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_cmd_suffix.");
	if ((gr_io_redirect(tokens, where) == true) || \
	(tok->type == E_TOKEN_WORD))//TODO, add check for pipe and stuff as for the rest
	{
		log_dbg2("Parser returned true at gr_cmd_suffix.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_cmd_suffix.");
		return false;
	}
}