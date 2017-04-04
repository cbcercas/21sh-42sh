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
** @return Returns true if parsing ok and false if error + printf error in stdout and log fatal
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

t_bool	parser_parse(t_array *tokens)
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
	return ok; //TODO, make the grammar functions print the errors !
}

t_bool gr_complete_cmd(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_complete_cmd.");
	if ((gr_list(tokens, where) == true) || (gr_list(tokens, where) == true && gr_separator(tokens, where) == true))
	{
		log_dbg3("Parser returned true at gr_complete_cmd.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_complete_cmd.");
		return false;
	}
}

t_bool gr_list(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_list.");
	if (((gr_separator_op(tokens, where) == true) && \
	(gr_and_or(tokens, where) == true)) || \
	(gr_and_or(tokens, where) == true) || \
	(gr_separator_op(tokens, where) == true))
	{
		log_dbg3("Parser returned true at gr_list.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_list.");
		return false;
	}
}

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

t_bool gr_separator(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_separator.");
	if ((gr_separator_op(tokens, where) == true) && (gr_linebreak(tokens, where) == true))
	{
		log_dbg3("Parser returned true at gr_separator.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_separator.");
		return false;
	}
}

t_bool gr_linebreak(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_linebreak.");
	if (gr_newline_list(tokens, where) == true)
	{
		log_dbg3("Parser returned true at gr_linebreak.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_linebreak.");
		return false;
	}
}

t_bool gr_newline_list(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_newline_list.");
	if (tok->type == E_TOKEN_SEMI)
	{
		log_dbg3("Parser returned true at gr_newline_list.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_newline_list.");
		return false;
	}
}

t_bool gr_and_or(t_array *tokens, size_t where)
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
		log_dbg3("Parser returned true at gr_and_or.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_and_or.");
		return false;
	}
}//TODO : Check for something after to && or || or else parsing error (check_and_if() check_or_if)

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

t_bool gr_check_and_if(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_pipe_sequence.");
	if (tok->type == E_TOKEN_AND_IF)
		if (tokens->used > where + 1)
			if (gr_complete_cmd(tokens, where + 1) == true)
				return true;
			else
			{
				log_dbg3("Parser returned false at gr_pipe_sequence.");
				return false;
			}
		else
		{
			log_dbg3("Parser returned false at gr_pipe_sequence.");
			return false;
		}
	else
	{
		log_dbg3("Parser returned false at gr_pipe_sequence.");
		return false;
	}
}

t_bool gr_pipeline(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_pipe_sequence.");
	if (gr_pipe_sequence(tokens, where) == true)
	{
		log_dbg3("Parser returned true at gr_pipe_sequence.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_pipe_sequence.");
		return false;
	}
}

t_bool gr_pipe_sequence(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_pipe_sequence.");
	if ((gr_command(tokens, where) == true) || \
	((tok->type == E_TOKEN_PIPE) && \
	(gr_linebreak(tokens, where) == true) && \
	(gr_command(tokens, where) == true)))
	{
		log_dbg3("Parser returned true at gr_pipe_sequence.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_pipe_sequence.");
		return false;
	} //TODO Check stuff after pipe
}

t_bool	gr_command(t_array *tokens, size_t where)
{
	log_info("Parser is at gr_command.");
	if (gr_simple_command(tokens, where) == true)
	{
		log_dbg3("Parser returned true at gr_command.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_command.");
		return false;
	}
}

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
		log_dbg3("Parser returned true at gr_simple_command.");
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
		log_dbg3("Parser returned true at gr_cmd_prefix.");
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
		log_dbg3("Parser returned true at gr_cmd_word.");
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
		log_dbg3("Parser returned true at gr_cmd_name.");
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
		log_dbg3("Parser returned true at gr_cmd_suffix.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_cmd_suffix.");
		return false;
	}
}

t_bool gr_io_redirect(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_io_redirect.");
	if ((gr_io_file(tokens, where) == true) || \
	((tok->type == E_TOKEN_IO_NUMBER) && \
	gr_io_file(tokens, where) == true) || \
	(gr_io_here(tokens, where) == true) || \
	((tok->type == E_TOKEN_IO_NUMBER) && \
	gr_io_here(tokens, where) == true))
	{
		log_dbg3("Parser returned true at gr_io_redirect.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_io_redirect.");
		return false;
	}
	//TODO, add check for pipe and stuff as for the rest
}

t_bool gr_io_file(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_io_file.");
	if (((tok->str[0] == '<') && gr_filename(tokens, where) == true) || \
	((tok->type == E_TOKEN_LESSAND) && (gr_filename(tokens, where) == true)) || \
	(((tok->str[0] == '>') && gr_filename(tokens, where) == true)) || \
	((tok->type == E_TOKEN_GREATAND) && (gr_filename(tokens, where) == true)) || \
	((tok->type == E_TOKEN_DGREAT) && (gr_filename(tokens, where) == true)) || \
	((tok->type == E_TOKEN_LESSGREAT) && (gr_filename(tokens, where) == true)))
	{
		log_dbg3("Parser returned true at gr_io_file.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_io_file.");
		return false;
	}
	//TODO, add check for pipe and stuff as for the rest
}


t_bool gr_io_here(t_array *tokens, size_t where) {
	t_token *tok;

	tok = (t_token *) array_get_at(tokens, where);
	log_info("Parser is at gr_io_here.");
	if ((tok->type == E_TOKEN_DLESS) && (gr_here_end(tokens, where) == true)) {
		log_dbg3("Parser returned true at gr_io_here.");
		return true;
	} else {
		log_dbg3("Parser returned false at gr_io_here.");
		return false;
	}
}

t_bool gr_filename(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_filename.");
	if (tok->type == E_TOKEN_WORD) //TODO, add check for pipe and stuff as for the rest
	{
		log_dbg3("Parser returned true at gr_filename.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_filename.");
		return false;
	}
}

t_bool gr_here_end(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_here_end.");
	if (tok->type == E_TOKEN_WORD) //TODO, add check for pipe and stuff as for the rest
	{
		log_dbg3("Parser returned true at gr_here_end.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_here_end.");
		return false;
	}
}

/*
 *
 * TODO for later, as debug lvl3
 *
 *
  	size_t		i;
	size_t nb_word;
	size_t nb_blank;
	size_t nb_newline;
	t_token *tok;

	nb_blank = 0;
	nb_word = 0;
	nb_newline = 0;
	i = 0;
	log_info("Parser: initializing");
	log_dbg3("Parser: user input is \n\n%s\n", input);
	log_dbg3("Parser: input is %zu long.", ft_strlen(input));
	log_dbg3("Parser: lexer returned %zu tokens to be parsed", tokens->used);
	while (i < tokens->used)
	{
		tok = (t_token *)array_get_at(tokens, i);
		if (tok->type == E_TOKEN_WORD)
			nb_word++;
		else if (tok->type == E_TOKEN_BLANK)
			nb_blank++;
		else if (tok->type == E_TOKEN_NEWLINE)
			nb_newline++;
		i++;
	}
	log_dbg3("Found %zu words", nb_word);
	log_dbg3("Found %zu blank spaces", nb_blank);
	log_dbg3("Found %zu newlines", nb_newline);
 */