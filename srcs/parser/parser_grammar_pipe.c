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

t_bool	gr_check_and_if(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_pipe_sequence.");
	if (tok->type == E_TOKEN_AND_IF)
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
				return (true);
			else
			{
				log_dbg3("Parser returned false at gr_pipe_sequence.");
				return (false);
			}
		else
		{
			log_dbg3("Parser returned false at gr_pipe_sequence.");
			return (false);
		}
	else
	{
		log_dbg3("Parser returned false at gr_pipe_sequence.");
		return (false);
	}
}

t_bool	gr_pipeline(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_pipe_sequence.");
	if (gr_pipe_sequence(tokens, where) == true)
	{
		log_dbg2("Parser returned true at gr_pipe_sequence.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_pipe_sequence.");
		return (false);
	}
}

t_bool	gr_pipe_sequence(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_pipe_sequence.");
	if ((gr_command(tokens, where) == true) || \
	((tok->type == E_TOKEN_PIPE) && \
	(gr_linebreak(tokens, where) == true) && \
	(gr_command(tokens, where) == true)))
	{
		log_dbg2("Parser returned true at gr_pipe_sequence.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_pipe_sequence.");
		return (false);
	}
}

/*
**TODO: Check stuff after pipe
*/

t_bool	gr_command(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_command.");
	if (gr_simple_command(tokens, where) == true)
	{
		log_dbg2("Parser returned true at gr_command.");
		return (true);
	}
	else
	{
		log_dbg3("Parser returned false at gr_command.");
		return (false);
	}
}
