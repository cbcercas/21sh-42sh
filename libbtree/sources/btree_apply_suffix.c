/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 11:23:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/17 11:45:27 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree.h>

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	if (root->left != NULL)
		btree_apply_infix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_infix(root->right, applyf);
	applyf(root->item);
}
