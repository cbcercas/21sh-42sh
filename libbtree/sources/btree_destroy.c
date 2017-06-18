/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 11:23:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/18 16:39:38 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree.h>

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
		free((*root)->left);
	if ((*root)->right != NULL)
		free((*root)->right);
	if ((*root))
		free((*root));
	(*root) = NULL;
}
