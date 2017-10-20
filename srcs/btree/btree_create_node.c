/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:49:00 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 16:14:31 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree/ft_btree.h>
#include <stdlib.h>
#include <ft_secu_malloc/ft_secu_malloc.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*btree;

	btree = NULL;
	if (!(btree = (t_btree*)ft_secu_malloc_lvl(sizeof(t_btree), 2)))
		return (NULL);
	btree->parent = NULL;
	btree->left = NULL;
	btree->right = NULL;
	btree->item = item;
	return (btree);
}

void	btree_insert_data(t_btree **root, void *item,\
													int (*cmpf)(void *, void *))
{
	if (!root)
		return ;
	if (!(*root))
		*root = btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
	{
		btree_insert_data(&(*root)->left, item, cmpf);
		(*root)->left->parent = (*root);
	}
	else
	{
		btree_insert_data(&(*root)->right, item, cmpf);
		(*root)->right->parent = (*root);
	}
}
