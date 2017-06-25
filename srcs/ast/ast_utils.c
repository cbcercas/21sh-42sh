/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/23 16:22:20 by gpouyat          ###   ########.fr       */
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

int	ast_val_cmp(t_token_type type)
{
	if ((type == E_TOKEN_SEMI) ||\
			(type == E_TOKEN_AND_IF) || (type == E_TOKEN_OR_IF))
		return (1);
	if (type == E_TOKEN_LESSGREAT)
		return (2);
	if (type == E_TOKEN_DLESS)
		return (3);
	if (type == E_TOKEN_DGREAT)
		return (4);
	if ((type == E_TOKEN_PIPE) || (type == E_TOKEN_AND))
		return (5);
	if (type == E_TOKEN_WORD)
		return (6);
	return (7);
}

int	ast_cmp(t_cmd *s1, t_cmd *s2)
{
	if (ast_val_cmp(s1->type) <= ast_val_cmp(s2->type))
		return (0);
	return (1);
}

char *ast_aff(t_cmd *cmd)
{
	return ((char *)cmd->str);
}

t_cmd	*ast_new_cmd(const char *str, size_t len, t_token_type type)
{
	t_cmd	*cmd;
	int		i;

	if (!str || !(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);
	cmd->type = type;
	cmd->str = ft_strsub(str, 0, len);
	ft_bzero((void *)&cmd->info, sizeof(t_info));
	return (cmd);
}
