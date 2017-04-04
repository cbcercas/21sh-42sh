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

t_bool gr_separator_op(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_separator_op.");
	if (tok->type == E_TOKEN_AND)
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
			{
				log_dbg3("Parser returned true at gr_separator_op.");
				return true;
			}
			else
			{
				log_dbg3("Parser returned false at gr_separator_op.");
				return false;
			}
		else
		{
			log_dbg3("Parser returned false at gr_separator_op.");
			return false;
		}
	else if (tok->type == E_TOKEN_SEMI)
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
			{
				log_dbg3("Parser returned true at gr_separator_op.");
				return true;
			}
			else
			{
				log_dbg3("Parser returned false at gr_separator_op.");
				return false;
			}
		else
		{
			log_dbg3("Parser returned true at gr_separator_op.");
			return true;
		}
	else
	{
		log_dbg3("Parser returned false at gr_separator_op.");
		return false;
	}
}

t_bool gr_check_or_if(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_check_or_if.");
	if (tok->type == E_TOKEN_OR_IF)
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
			{
				log_dbg3("Parser returned true at gr_check_or_if.");
				return true;
			}
			else
			{
				log_dbg3("Parser returned false at gr_check_or_if.");
				return false;
			}
		else
		{
			log_dbg3("Parser returned false at gr_check_or_if.");
			return false;
		}
	else
	{
		log_dbg3("Parser returned false at gr_check_or_if.");
		return false;
	}
}