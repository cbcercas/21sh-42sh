/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 11:23:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/17 11:45:34 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree/ft_btree.h>

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	if (root->left != NULL)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right != NULL)
		btree_apply_infix(root->right, applyf);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	applyf(root->item);
	if (root->left != NULL)
		btree_apply_prefix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_prefix(root->right, applyf);
}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	if (root->left != NULL)
		btree_apply_suffix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}