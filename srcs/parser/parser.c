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
#include <core/main.h>

/*
** @brief Initializes the parser for the program
**
** @param tokens  The tokens sent by the lexer
** @param input   The input the user sent
** @return Returns nothing for now
**/

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
	logger_init(7, PROG_NAME, "log.log");
	log_info("Parser: initializing");
	log_info("Parser: user input is %s", input);
	log_info("Parser: input is %zu long.", ft_strlen(input));
	log_info("Parser: lexer returned %zu tokens to be parsed", tokens->used);
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
	log_info("Found %zu words", nb_word);
	log_info("Found %zu blank spaces", nb_blank);
	log_info("Found %zu newlines", nb_newline);
}
