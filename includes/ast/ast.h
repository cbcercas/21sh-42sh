/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:44:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/19 14:39:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <btree/ft_btree.h>
# include <types/bool.h>
# include <logger.h>
# include <libft.h>
# include <lexer/lexer.h>

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char const			*str;
	t_token_type		type;
};

t_btree	*ast_built(t_btree *ast, t_array *tokens, size_t cnt, size_t lim);
char	*ast_aff(t_cmd *cmd);

#endif
