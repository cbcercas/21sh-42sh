/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/18 13:40:53 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ast/ast.h>

void	ast_del_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->av)
	{
		free(cmd->av);
		cmd->av = NULL;
	}
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
	int i;

	i = 0;
	while(cmd->av[i] && cmd->av[i + 1])
	{
		ft_printf("%s ", cmd->av[i]);
		i++;
	}
	if (cmd->av[i])
		ft_printf("%s", cmd->av[i]);
	return ("");
}

BOOL	ast_prio(t_token_type type, int prio, size_t cnt, t_array *expands)
{
	if ( prio == 1 && ((type == E_TOKEN_SEMI) ||\
				(type == E_TOKEN_AND_IF) || (type == E_TOKEN_OR_IF)))
		return (true);
	if (prio == 2 && (type == E_TOKEN_LESSGREAT))
		return (true);
	if ( prio == 2 && (type == E_TOKEN_DLESS))
		return (true);
	if ( prio == 4 && (type == E_TOKEN_DGREAT))
		return (true);
	if ( prio == 5 && ((type == E_TOKEN_PIPE) || (type == E_TOKEN_AND)))
		return (true);
	if ( prio == 6 && (ast_is_greatand(expands, cnt, type)))
		return (true);
	if ( prio == 7 && (type == E_TOKEN_WORD || type == E_TOKEN_IO_NUMBER))
		return (true);
	return (false);
}

t_cmd	*ast_new_cmd(t_array *expands, int start, int end, t_token_type type)
{
	t_cmd						*cmd;
	t_exp 					*exp;
	int		i;
	size_t					cnt;

	i = 0;
	cnt = 0;
	if ((end - start) < 0)
		return (NULL);
	if (!expands || !(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);
	ft_bzero(cmd, sizeof(t_cmd));
	if (!(cmd->av = (char **)malloc(sizeof(char **) * (end - start + 2))))
		return(NULL);
	cmd->type = type;
	while ( i < (end - start) && (exp = (t_exp*)array_get_at(expands, start + i)))// TODO: peut etre pas <= mais juste <
	{
		if (exp->str && exp->type != E_TOKEN_BLANK)
			cmd->av[cnt++] = exp->str->s;
		i++;
	}
	cmd->av[cnt] = NULL;
	ft_bzero((void *)&cmd->info, sizeof(t_info));
	return (cmd);
}
