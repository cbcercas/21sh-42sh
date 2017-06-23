/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:47:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/20 17:29:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

t_btree	*ast_create(t_array *tokens)
{
	t_lim			lim;
	t_btree		*ast;

	ast = NULL;
	lim.cnt = 0;
	lim.lim = 10000;
	ast = ast_built1(ast, tokens, lim);
	return (ast);
}
