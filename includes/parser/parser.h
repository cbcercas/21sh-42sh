/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:02:17 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/21 10:22:54 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <lexer/lexer.h>
# include <logger/logger.h>
# include <parser/grammar.h>

/*
** @file parser.c
**
** @brief initialize the parser
*/

enum e_grammar_sym
{
	complete_command = 100, //done
	list, //done
	separator_op, //done
	separator, //done
	and_or, //done
	pipeline, //done
	linebreak, //done
	pipe_sequence, //done
	newline_list, //done
	command, //done
	simple_command, //done
	cmd_prefix, //done
	cmd_word, //done
	cmd_suffix, //done
	cmd_name, //done
	io_redirect, //done
	io_file, //done
	io_here, //done
	filename, //done
	here_end, //done
	SYM_MAX

};

// TODO : Reorganiser l'enum parce que il n'est pas dans l'ordre du tableau !!

void	parser_init(t_array *tokens, char *input);

#endif
