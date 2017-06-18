/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:49:00 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/18 20:39:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree/ft_btree.h>

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!root)
		return ;
	if (!(*root))
		*root = btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
