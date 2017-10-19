/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/14 12:51:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

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

int sh_process_exec(t_sh_data *data, t_btree *ast, t_list *fds[4], int wait_flag)
{
	t_cmd	*item;

	if (!ast)
		return (g_ret);
	item = (t_cmd *)ast->item;
	if (item->type == E_TOKEN_WORD)
		return (sh_exec_simple(data, item, fds, wait_flag));
	else if(item->type == E_TOKEN_SEMI)
	{
		sh_process_exec(data, ast->left, fds, 0);
		return (sh_process_exec(data, ast->right, fds, wait_flag));
	}
	else if(item->type == E_TOKEN_AND_IF)
		return((sh_process_exec(data, ast->left, fds, wait_flag) == 0) && \
				(sh_process_exec(data, ast->right, fds, wait_flag) == 0));
	else if(item->type == E_TOKEN_OR_IF)
		return((sh_process_exec(data, ast->left, fds, wait_flag) == 0) || \
			(sh_process_exec(data, ast->right, fds, wait_flag) == 0));
	else if((item->type == E_TOKEN_LESSGREAT) || (item->type == E_TOKEN_DGREAT))
			return(sh_exec_redir(data, ast, fds, wait_flag));
	else if(item->type == E_TOKEN_GREATAND || item->type == E_TOKEN_LESSAND)
		return(sh_exec_greatand(data, ast, fds, wait_flag));
	else if(item->type == E_TOKEN_DLESS)
		return(sh_heredoc(data, ast, fds, wait_flag));
	else if (item->type == E_TOKEN_PIPE)
		return (sh_exec_pipe(data, ast, fds, wait_flag));
	return (-1);
}

int		exec_exec(t_sh_data *data, t_btree *ast)
{
	t_list	*fds[4];

		if (!ast)
			return (-1);
	fds[STDIN_FILENO] = NULL;
	fds[STDOUT_FILENO] = NULL;
	fds[STDERR_FILENO] = NULL;
	fds[3] = NULL;
	return (sh_process_exec(data, ast, fds, 0));
}
