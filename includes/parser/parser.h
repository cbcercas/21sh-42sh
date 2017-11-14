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

t_return	parser_parse(t_array *tokens);

#endif
