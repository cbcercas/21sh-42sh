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


static const uint32_t grammar[SYM_MAX][SYM_MAX][4] =
{
//complete_command
	{
		{
			list,
			separator
		},
		{
			list
		}
	},
// list
	{
		{
			list,
			separator_op,
			and_or
		},
		{
			and_or
		}
	},
// and_or
	{
		{
				pipeline
		},
			{
					and_or,
					E_TOKEN_AND_IF,
					linebreak,
					pipeline
			},
			{
					and_or,
					E_TOKEN_OR_IF,
					linebreak,
					pipeline
		}
	},
// pipeline
	{
		{
			pipe_sequence
		}
	},
// newline_list
	{
		{
			E_TOKEN_NEWLINE
		},
		{
			newline_list,
				E_TOKEN_NEWLINE
		}
	},
// separator_op
	{
		{
			'&',
			';'
		}
	},
// separator
	{
		{
			separator_op,
			linebreak
		}
	},
//linebreak
	{
		{
			newline_list
		}
	},
//pipe_sequence
	{
		{
			command
		},
		{
			pipe_sequence,
			'|',
			linebreak,
			command
		}
	},
//command
	{
		{
			simple_command
		}
	},
//simple_command
	{
		{
			cmd_prefix,
			cmd_word,
			cmd_suffix
		},
		{
			cmd_prefix,
			cmd_word
		},
		{
			cmd_prefix
		},
		{
			cmd_name,
			cmd_suffix
		},
		{
			cmd_name
		}
	},
//cmd_prefix
	{
		{
			io_redirect
		},
		{
			cmd_prefix,
			io_redirect
		}
	},
//cmd_word
	{
		{
				E_TOKEN_WORD
		}
	},
//cmd_name
	{
		{
				E_TOKEN_WORD
		}
	},
//cmd_suffix
	{
		{
			io_redirect
		},
		{
			cmd_suffix,
			io_redirect
		},
		{
				E_TOKEN_WORD
		},
		{
			cmd_suffix,
				E_TOKEN_WORD
		}
	},
//io_redirect
	{
		{
			io_file
		},
		{
				E_TOKEN_IO_NUMBER,
			io_file
		},
		{
			io_here
		},
		{
				E_TOKEN_IO_NUMBER,
			io_here
		}
	},
//io_file
	{
		{
			'<',
			filename
		},
		{
				E_TOKEN_LESSAND,
			filename
		},
		{
			'>',
			filename
		},
		{
				E_TOKEN_GREATAND,
			filename
		},
		{
				E_TOKEN_DGREAT,
			filename
		},
		{
				E_TOKEN_LESSGREAT,
			filename
		}
	},
//io_here
	{
		{
				E_TOKEN_DLESS,
			here_end
		}
	},
//filename
	{
		{
				E_TOKEN_WORD
		}
	},
//here_end
	{
		{
				E_TOKEN_WORD
		}
	}
};



/*
** @brief Initializes the parser for the program
**
** @param tokens  The tokens sent by the lexer
** @return Returns nothing for now
*/

void dbg_printtok_str(t_array *tokens, size_t i)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, i);
	lexer_print_token(tok);
	ft_putstr(": ");
	ft_putnstr(tok->str, tok->len);
	ft_putchar('\n');
}

void	parser_init(t_array *tokens)
{
	size_t i;
	t_bool ok;

	i = 0;
	while (i < tokens->used)
	{
		dbg_printtok_str(tokens, i);
		if (gr_complete_cmd(tokens, i) == true)
			ok = true;
		else
			ok = false;
		i++;
	}
	if (ok == true)
		ft_printf("Parsing done and ok, let's roll !\n");
	else
		ft_printf("Parsing error\n");
}

t_bool gr_complete_cmd(t_array *tokens, size_t where)
{
	if ((gr_list(tokens, where) == true) || (gr_list(tokens, where) == true && gr_separator(tokens, where) == true))
		return  true;
	else
		return false;
}

t_bool gr_list(t_array *tokens, size_t where)
{

	if (((gr_separator_op(tokens, where) == true) && (gr_and_or(tokens, where) == true)) || (gr_and_or(tokens, where) == true))
		return true;
	else
		return false;
}

t_bool gr_separator_op(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	if ((tok->type == E_TOKEN_AND) ||  (tok->type == E_TOKEN_NEWLINE))
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
				return true;
			else
				return false;
		else
			return false;
	return false;
}

t_bool gr_separator(t_array *tokens, size_t where)
{
	if ((gr_separator_op(tokens, where) == true) && (gr_linebreak(tokens, where) == true))
		return true;
	return false;
}

t_bool gr_linebreak(t_array *tokens, size_t where)
{
	if (gr_newline_list(tokens, where) == true)
		return true;
	return false;
}

t_bool gr_newline_list(t_array *tokens, size_t where)
{
	t_token *tok;
	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_SEMI)
		return true;
	return false;
}

t_bool gr_and_or(t_array *tokens, size_t where)
{
	t_token *tok;
	tok = (t_token *)array_get_at(tokens, where);
	if ((gr_pipeline(tokens, where) == true) || ((gr_check_and_if(tokens, where) == true) && (gr_linebreak(tokens, where)) && (gr_pipeline(tokens, where))) || (gr_check_or_if(tokens, where) == true) && (gr_linebreak(tokens, where)) && (gr_pipeline(tokens, where)))
		return true; //TODO : Check for something after to && or || or else parsing error (check_and_if() check_or_if)
	else
		return false;
}

t_bool gr_check_or_if(t_array *tokens, size_t where)
{
	t_token *tok;
	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_OR_IF)
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
				return true;
			else
				return false;
		else
			return false;
	return false;
}

t_bool gr_check_and_if(t_array *tokens, size_t where)
{
	t_token *tok;
	tok = (t_token *)array_get_at(tokens, where);
	if (tok->type == E_TOKEN_AND_IF)
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
				return true;
			else
				return false;
		else
			return false;
	return false;
}

t_bool gr_pipeline(t_array *tokens, size_t where)
{
	return true;
}