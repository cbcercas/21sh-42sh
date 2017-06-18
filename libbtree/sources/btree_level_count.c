/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 19:51:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/18 09:46:44 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_max(int left, int right)
{
	if (left > right)
		return (left);
	else
		return (right);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_max(btree_level_count(root->left),
	btree_level_count(root->right)) + 1);
}
