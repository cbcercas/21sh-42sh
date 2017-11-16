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

# include <parser/enum.h>
# include <core/return.h>
# include <lexer/lexer.h>
# include <core/progname.h>
# include <stdio.h>

/*
** @file   parser.h
**
** @brief  Function prototypes for the parser module
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file parser.c
**
** @brief The functions for the parser
*/

t_return	parser_parse(t_array *tokens);

#endif
