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
** @param input   The input the user sent
** @return Returns nothing for now
*/

void	parser_init(t_array *tokens, char *input)
{
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
		ft_printf("\nSTR = %s\n", tok->str);
	}
	log_dbg3("Found %zu words", nb_word);
	log_dbg3("Found %zu blank spaces", nb_blank);
	log_dbg3("Found %zu newlines", nb_newline);
	if (gr_complete_cmd(&tokens, input) == false)
		ft_printf("PARSING ERROR\n");
	else
		ft_printf("PARSING DONE\n");
}

t_bool gr_complete_cmd(t_array *tokens, char *input)
{
	if ((gr_list(&tokens, input) == true) || (gr_list(&tokens, input) == true && gr_separator(&tokens, input) == true))
		return  true;
	else
		return false;
}

//(gr_list(&tokens, input) == true) &&

t_bool gr_list(t_array *tokens, char *input)
{
	if (((gr_list(&tokens, input) == true) && (gr_separator_op(&tokens, input) == true) && (gr_and_or(&tokens, input) == true)) || (gr_and_or(&tokens, input) == true))
		return true;
	else
		return false;
}

t_bool gr_separator_op(t_array *tokens, char *input)
{
	return true;
}

t_bool gr_and_or(t_array *tokens, char *input)
{
	return true;
}

t_bool gr_separator(t_array *tokens, char *input)
{
	return true;
}