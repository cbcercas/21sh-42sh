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
	E_RET_LEXER_OK = 10,
	E_RET_LEXER_ERROR = 11,
	E_RET_LEXER_INCOMPLETE = 12,
	E_RET_LEXER_SQUOTE = 13,
	E_RET_LEXER_BQUOTE = 14,
	E_RET_LEXER_DQUOTE = 15,
	E_RET_LEXER_PIPE = 16,
	E_RET_PARSER_OK = 17,
	E_RET_PARSER_ERROR = 18,
	E_RET_EXPAND_OK = 19,
	E_RET_EXPAND_ERROR = 20,
	E_RET_AST_OK = 21,
	E_RET_AST_ERROR = 22
};

#endif