/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 19:51:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 14:04:07 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree/ft_btree.h>

/*
** @brief calculates the lenght of a string
**
** @param s string
**
** @return Seturns the lenght of s
*/

static int		btree_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//Euh WTF TODO why use btree_strlen() instead of strlen ??

/*
** @brief Displays a btree item
**
** @param str the btree item to display
**
** @return void
*/

static void		btree_display_str(char *str)
{
	if (!str)
	{
		write(1, "NULL", 4);
		return ;
	}
	write(1, str, btree_strlen(str));
}

/*
** @brief Prints a node of the btree
** @param this The btree node to print
** @param current_level the current level in the btree
** @param max_level The max depth in the btree
** @param applyf (TODO)
*/

static void			node_print(t_btree *this, int current_level, int max_level,\
														char *(*applyf)(void *))
{
	int i;

	i = 0;
	if (this)
	{
		node_print(this->right, current_level + 1, max_level, applyf);
		while (i++ < current_level)
			btree_display_str("    ");
		btree_display_str(applyf(this->item));
		btree_display_str("\n");
		node_print(this->left, current_level + 1, max_level, applyf);
		return ;
	}
	if (current_level < max_level)
	{
		node_print(NULL, current_level + 1, max_level, applyf);
		while (i++ < current_level)
			btree_display_str("    ");
		btree_display_str("..\n");
		node_print(NULL, current_level + 1, max_level, applyf);
	}
}

/*
** @brief Prints the btree entirely
** @param this The btree to be printed
** @param applyf (TODO)
*/

void			btree_print(t_btree *this, char *(*applyf)(void *))
{
	if (!this)
		return ;
	btree_display_str("[--- Display tree ---]\n");
	node_print(this, 0, btree_level_count(this), applyf);
	btree_display_str("\n\n");
}
