/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/18 12:24:28 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

void	ast_del_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->str)
		ft_strdel((char **)&(cmd->str));
	free(cmd);
	cmd = NULL;
}

void ast_built2_swap(t_btree *ast)
{
		t_btree		*tmp;

		if (!ast)
			return ;
		tmp = ast->left;
		ast->left = ast->right;
		ast->right = tmp;
}

char *ast_aff(t_cmd *cmd)
{
	return ((char *)cmd->str);
}

t_cmd	*ast_new_cmd(const char *str, size_t len, t_token_type type)
{
	t_cmd	*cmd;

	if (!str || !(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);
	cmd->type = type;
	cmd->str = ft_strsub(str, 0, len);
	ft_bzero((void *)&cmd->info, sizeof(t_info));
	return (cmd);
}
