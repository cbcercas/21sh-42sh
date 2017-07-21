/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 11:23:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/21 14:37:47 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree/ft_btree.h>

void	btree_destroy(t_btree **root, void (*del)(void *))
{
	if (!root || !(*root))
		return ;
	if ((*root)->item && del)
		btree_apply_prefix(*root, del);
	if ((*root)->left != NULL)
		btree_destroy(&(*root)->left, NULL);
	if ((*root)->right != NULL)
		btree_destroy(&(*root)->right, NULL);
	if ((*root)->left != NULL)
		ft_secu_free((*root)->left);
	if ((*root)->right != NULL)
		ft_secu_free((*root)->right);
	if ((*root))
		ft_secu_free((*root));
	(*root) = NULL;
}
