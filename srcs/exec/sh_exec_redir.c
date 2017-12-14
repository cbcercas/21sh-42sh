/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 11:49:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/15 12:45:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

/*
** @brief   find, test and add the second fd in fd list (redir great)
** @param  item    struct of command
** @param  fds     The list of fd
** @param  fd      the first fd
**
** @return true if everything is ok, false otherwise
*/

static BOOL		redir_great(t_cmd *item, t_array *fds, int fd)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (ft_isdigit(item->av[0][0]) && ft_strlen(item->av[0]) == 1)
			sh_exec_new_redir_fd(fds, ft_atoi(item->av[0]), fd, false);
		else
			return (false);
	}
	else
		sh_exec_new_redir_fd(fds, STDOUT_FILENO, fd, false);
	return (true);
}

/*
** @brief   find, test and add the second fd in fd list (redir less)
** @param  item    struct of command
** @param  fds     The list of fd
** @param  fd      the first fd
**
** @return true if everything is ok, false otherwise
*/

static BOOL		redir_less(t_cmd *item, int fd, t_array *fds)
{
	if (ft_isdigit(item->av[0][0]))
	{
		if (ft_isdigit(item->av[0][0]) && ft_strlen(item->av[0]) == 1)
			sh_exec_new_redir_fd(fds, ft_atoi(item->av[0]), fd, false);
		else
			return (false);
	}
	else
		sh_exec_new_redir_fd(fds, STDIN_FILENO, fd, false);
	return (true);
}

/*
** @brief   init redir, find and open first fd
** @param  ast     The AST (Analyse Syntax Tree[binary])
** @param  item    struct of command
** @param  fd      the first fd
**
** @return true if everything is ok, false otherwise
*/

static BOOL		sh_exec_redir_init(t_btree *ast, t_cmd **item, int *fd)
{
	if (!ast)
		return (false);
	*item = (t_cmd *)ast->item;
	if ((*fd = sh_open_exec(ast)) == -1)
	{
		*get_cmd_ret() = EXIT_FAILURE;
		return (false);
	}
	return (true);
}

/*
** @brief   push fd in fd list and execute
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
** @param  fds     The list of fd
**
** @return ret of exec
*/
int				sh_exec_redir(t_sh_data *data, t_btree *ast, t_array *fds)
{
	int		fd;
	t_cmd	*item;

	if (!sh_exec_redir_init(ast, &item, &fd))
		return (*get_cmd_ret());
	if (item->type == E_TOKEN_DGREAT || ft_strequ(item->av[0], ">")
		|| ft_strequ(item->av[1], ">"))
	{
		if (!redir_great(item, fds, fd))
			return (*get_cmd_ret() = 2);
	}
	else if (!redir_less(item, fd, fds))
		return (*get_cmd_ret() = 2);
	sh_process_exec(data, ast->left, fds);
	return (*get_cmd_ret());
}
