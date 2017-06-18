/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 09:54:10 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/18 17:35:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_btree.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while ((s1[0] == s2[0]) && (s1[0] != '\0' || s2[0] != '\0'))
	{
		s1++;
		s2++;
	}
	if (s1[0] == s2[0])
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char *aff(char *s)
{
	return (s);
}

int		main()
{
	t_btree		*tree;
	t_btree		*node;

	tree = NULL;
	tree = btree_create_node(strdup("0"));
	btree_insert_data(&tree, strdup("3"), (int (*)(void*, void*))&ft_strcmp);
	btree_insert_data(&tree, strdup("4"), (int (*)(void*, void*))&ft_strcmp);
	btree_insert_data(&tree, strdup("1"), (int (*)(void*, void*))&ft_strcmp);
	btree_insert_data(&tree, strdup("toto"), (int (*)(void*, void*))&ft_strcmp);
	btree_insert_data(&tree, strdup("2"), (int (*)(void*, void*))&ft_strcmp);

	printf("\n");
	btree_print(tree, (char * (*)(void*))&aff);

	printf("\n%s\n", "prefix:");
	btree_apply_prefix(tree, (void (*)(void*))&printf);


	printf("\n%s\n", "sufix:");
	btree_apply_suffix(tree, (void (*)(void*))&printf);


	printf("\n%s\n", "infix:");
	btree_apply_infix(tree, (void (*)(void*))&printf);
	printf("%s\n", "");

	printf("%s\n", "search toto:");
	node = btree_search_item(tree, "toto", (int (*)(void*, void*))&ft_strcmp);
	if (node == NULL)
		printf("toto=%s\n", "NULL");
	else
		printf("toto=%s\n", (char *)node->item);

		printf("%s%d\n", "nb noeud sur la plus grande branche:", btree_level_count(tree));
	btree_destroy(&tree, free);
}
