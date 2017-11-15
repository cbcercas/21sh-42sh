/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:49:00 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/18 20:39:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree/ft_btree.h>

/*
** @brief Searches for an item in the btre
**
** @param root The btree to search
** @param data_ref The reference data to search (?TODO)
** @param cmpf (TODO)
**
** @return returns the found value (TODO)
*/

void		*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	if (root == NULL)
		return (0);
	if (cmpf(data_ref, root->item) < 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	else if (cmpf(data_ref, root->item) == 0)
		return (root);
	else if (cmpf(data_ref, root->item) > 0)
		return (btree_search_item(root->right, data_ref, cmpf));
	else
		return (0);
}

/*
** @brief Destroys the btree
**
** @param root The btree to be destroyed
** @param del The function used to del (TODO?)
**
** @return void
*/

void		btree_destroy(t_btree **root, void (*del)(void *))
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

/*
** @brief Returns the biggest integer
** @param left First integer to test
** @param right Second integet to test
** @return Returns the biggest
*/

int			ft_max(int left, int right)
{
	if (left > right)
		return (left);
	else
		return (right);
}

/*
** @brief (TODO)
** @param root The btree
** @return (TODO)
*/

int			btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_max(btree_level_count(root->left),
					btree_level_count(root->right)) + 1);
}
