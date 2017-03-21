/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:43:16 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/20 10:41:34 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <logger/logger.h>

/*
** @brief Initializes the parser for the program
**
** @param tokens  The tokens sent by the lexer
** @param input   The input the user sent
** @return Returns nothing for now
*/

static const uint32_t grammar[][][] =
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
					AND_IF,
					linebreak,
					pipeline,
		},
		{
			and_or,
					OR_IF,
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
			NEWLINE
		},
		{
			newline_list,
					NEWLINE
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
	}
};

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
	}
	log_dbg3("Found %zu words", nb_word);
	log_dbg3("Found %zu blank spaces", nb_blank);
	log_dbg3("Found %zu newlines", nb_newline);
}