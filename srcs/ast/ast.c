/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:47:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 13:37:38 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

char		*ast_aff_dbg(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->av[i] && cmd->av[i + 1])
	{
		log_dbg3("Ast builtind '%s' ", cmd->av[i]);
		i++;
	}
	if (cmd->av[i])
		log_dbg3("Ast building '%s' ", cmd->av[i]);
	return ("");
}



int		ast_val_cmp(t_token_type type)
{
	if (ISSEP(type))
		return (1);
	if (ISPIPE(type))
		return (2);
	if (ISRED(type))
		return (3);
	if (type == E_TOKEN_AND)
		return (4);
	if (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER)
		return (5);
	return (6);
}

int		ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_val_cmp(s1->type) <= ast_val_cmp(s2->type))
		return (0);
	return (1);
}

t_btree	*ast_create(t_array *expands)
{
	t_lim		lim;
	t_btree		*ast;

	ast = NULL;
	lim.cnt = 0;
	lim.lim = 10000;
	ast = ast_built(ast, expands, lim, 1);
	log_dbg1("Ast created.");
	return (ast);
}
