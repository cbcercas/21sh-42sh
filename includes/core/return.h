/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:04:39 by chbravo-          #+#    #+#             */
/*   Updated: 2017/09/18 21:49:58 by chbravo-          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETURN_H
# define RETURN_H

typedef enum e_return	t_return;

enum	e_return
{
	E_RET_LEXER_OK = 100,
	E_RET_LEXER_ERROR = 101,
	E_RET_LEXER_INCOMPLETE = 102,
	E_RET_LEXER_SQUOTE = 103,
	E_RET_LEXER_BQUOTE = 104,
	E_RET_LEXER_DQUOTE = 105,
	E_RET_LEXER_PIPE = 106,
	E_RET_PARSER_OK = 107,
	E_RET_PARSER_ERROR = 108,
	E_RET_EXPAND_OK = 109,
	E_RET_EXPAND_ERROR = 110,
	E_RET_AST_OK = 111,
	E_RET_AST_ERROR = 112,
	E_RET_EMPTY_LINE = 113,
	E_RET_NEW_PROMPT = 114
};

#endif