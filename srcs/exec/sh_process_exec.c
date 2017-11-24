/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/15 19:25:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief         handle ast before exec
**                it is recurcive function
**                fisrt is ast->left (branch left of binary tree AST)
**                if it is WORD so execute "normal"
**                if OR it is: "normal" OR "normal"
**                etc
**
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
**
** @return     -1 on error or unknow TOKEN
*/

int		sh_process_exec(t_sh_data *data, t_btree *ast, t_list **fds)
{
	if (!ast)
		return (*get_cmd_ret());
	if (((t_cmd *)ast->item)->type == E_TOKEN_SEMI)
	{
		sh_process_exec(data, ast->left, fds);
		return (sh_process_exec(data, ast->right, fds));
	}
	else if (((t_cmd *)ast->item)->type == E_TOKEN_AND_IF)
		return (!((sh_process_exec(data, ast->left, fds) == 0) &&
				(sh_process_exec(data, ast->right, fds) == 0)));
	else if (((t_cmd *)ast->item)->type == E_TOKEN_OR_IF)
		return (!((sh_process_exec(data, ast->left, fds) == 0) ||
				(sh_process_exec(data, ast->right, fds) == 0)));
	else if ((((t_cmd *)ast->item)->type == E_TOKEN_LESSGREAT) || (((t_cmd *)
					ast->item)->type == E_TOKEN_DGREAT))
		return (sh_exec_redir(data, ast, fds));
	else if (((t_cmd *)ast->item)->type == E_TOKEN_GREATAND || ((t_cmd *)
				ast->item)->type == E_TOKEN_LESSAND)
		return (sh_exec_greatand(data, ast, fds));
	else if (((t_cmd *)ast->item)->type == E_TOKEN_DLESS)
		return (sh_exec_heredoc(data, ast, fds));
	else if (((t_cmd *)ast->item)->type == E_TOKEN_PIPE)
		return (sh_exec_pipe(data, ast, fds));
	else
		return (sh_exec_simple(data, ((t_cmd *)ast->item), fds));
}

int		exec_exec(t_sh_data *data, t_btree *ast)
{
	t_list	*fds[FD_SETSIZE + 1];
	int		cnt;

	if (!ast)
		return (-1);
	cnt = 0;
	*is_in_pipe() = false;
	while (cnt < FD_SETSIZE + 1)
	{
		fds[cnt] = NULL;
		cnt++;
	}
	remove_useless();
	*get_cmd_ret() = sh_process_exec(data, ast, fds);
	exec_list_fd_destroy(fds);
	return (*get_cmd_ret());
}
