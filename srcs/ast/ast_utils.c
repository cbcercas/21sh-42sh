/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/25 18:56:57 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

void	ast_del_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	//if (cmd->str)
		//ft_strdel((char **)&(cmd->str));
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
	return ((char *)cmd->exp->str);
}

t_cmd	*ast_new_cmd(t_exp *exp)
{
	t_cmd	*cmd;
	int		i;

	if (!exp || !(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);
	cmd->exp = exp;
	ft_bzero((void *)&cmd->info, sizeof(t_info));
	return (cmd);
}
