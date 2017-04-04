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

/*
**enum e_grammar_sym
**{
**	complete_command = 100,
**	list,
**	separator_op,
**	separator,
**	and_or,
**	pipeline,
**	linebreak,
**	pipe_sequence,
**	newline_list,
**	command,
**	simple_command,
**	cmd_prefix,
**	cmd_word,
**	cmd_suffix,
**	cmd_name,
**	io_redirect,
**	io_file,
**	io_here,
**	filename,
**	here_end,
**	SYM_MAX
**};
*/

t_bool	parser_parse(t_array *tokens);

#endif
