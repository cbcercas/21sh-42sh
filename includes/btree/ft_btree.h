/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:44:56 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/23 15:22:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BTREE_H__
# define __FT_BTREE_H__

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_btree
{
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
	void						*item;
}									t_btree;

t_btree						*btree_create_node(void *item);
void							btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void							btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void							btree_apply_infix(t_btree *root, void (*applyf)(void *));
void							btree_destroy(t_btree **root, void (*del)(void *));
void							btree_insert_data(t_btree **root, void *item,
	 									int (*cmpf)(void *, void *));
int								btree_level_count(t_btree *root);
void 							*btree_search_item(t_btree *root, void *data_ref,
												int (*cmpf)(void *, void *));
void  						btree_print(t_btree *this, char *(*applyf)(void *));

#endif
