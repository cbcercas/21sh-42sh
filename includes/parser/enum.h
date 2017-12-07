/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SSG <SSG@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 15:52:55 by SSG               #+#    #+#             */
/*   Updated: 2017/11/21 13:47:50 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include <inttypes.h>

typedef uint32_t	t_token_type;

/*
** @file enum.h
**
** @brief contains the enum for token types
*/

enum	e_token_type
{
	E_TOKEN_NONE,
	E_TOKEN_BLANK,
	E_TOKEN_NEWLINE,
	E_TOKEN_WORD,
	E_TOKEN_SQUOTE,
	E_TOKEN_BQUOTE,
	E_TOKEN_DQUOTE,
	E_TOKEN_PIPE,
	E_TOKEN_LESSGREAT,
	E_TOKEN_AND,
	E_TOKEN_SEMI,
	E_TOKEN_IO_NUMBER,
	E_TOKEN_DLESS,
	E_TOKEN_DGREAT,
	E_TOKEN_OR_IF,
	E_TOKEN_AND_IF,
	E_TOKEN_LESSAND,
	E_TOKEN_GREATAND,
	E_TOKEN_MAX
};

#endif
