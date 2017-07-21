/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:49:00 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 15:10:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree/ft_btree.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*btree;

	btree = NULL;
	if (!(btree = (t_btree*)ft_secu_malloc_lvl(sizeof(t_btree), M_LVL_AST)))
		return (NULL);
	btree->parent = NULL;
	btree->left = NULL;
	btree->right = NULL;
	btree->item = item;
	return (btree);
}
