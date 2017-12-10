/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:53:32 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/08 12:07:14 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

/*
** @brief Frees the `t_cmd` struct and it's content.
** This function will check if `cmd` isn't NULL beforehand. If it isn't,
** it will free securely the `cmd->av` and set it to NULL before freeing the
** struct `cmd` itself.
**
** @param cmd The `cmd` struct to be freed
*/

void			ast_del_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->av)
	{
		ft_secu_free(cmd->av);
		cmd->av = NULL;
	}
	ft_secu_free(cmd);
}

/*
** @brief Displays the content of a given `t_cmd`.
** This function will loop through `cmd->av` from 0 and print them.
**
** @param cmd The `t_cmd` struct to display the contents from
**
** @return This function will return an empty string if successful.\n
** Otherwise, it will return the string `"NULL"`.
*/

char			*ast_aff(t_cmd *cmd)
{
	int i;

	i = 0;
	if (!cmd || !cmd->av)
		return ("NULL");
	while (cmd->av[i] && cmd->av[i + 1])
	{
		ft_printf("%s ", cmd->av[i]);
		i++;
	}
	if (cmd->av[i])
		ft_printf("%s", cmd->av[i]);
	return ("");
}

/*
** @brief Searches for the previous token with greater priority
**
** @param expands Contains the expanded user input
** @param prio Priority for tokens:\n
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
** @param lim Contains the virtual limits used by the AST.
**
** @return Returns a `t_exp` containing either the previous token or `NULL`.
*/

t_exp			*ast_search(t_array *expands, t_lim *lim, int prio)
{
	t_exp		*exp;

	exp = NULL;
	while (lim->cnt >= lim->lim && lim->cnt >= 0)
	{
		lim->cnt--;
		exp = (t_exp *)array_get_at(expands, (size_t)lim->cnt);
		if (exp && ast_associate_prio(exp->type, prio, lim->cnt, expands))
			break ;
	}
	return (exp);
}

/*
** @brief Mallocs `cmd` and `cmd->av` for ast_new_cmd().
**
** @param expands Contains the expanded user input in a token array form
** @param start This is the position of the first token to merge
** @param end This is the position of the last token to merge
** @param cmd This is the command struct.
**
** @return If a malloc fails, the shell exits immediatly.\n
** Else, if `start` is bigger than `end`, `false` is returned.\n
** Otherwise, `true` will be returned.
*/

static BOOL		ast_new_init(t_array *expands, ssize_t start, ssize_t end,
								t_cmd **cmd)
{
	if ((end - start) < 0)
		return (false);
	log_dbg1("AST: CREATION ONE start_cnt: %d end_cnt: %d", start, end);
	if (!expands || !(*cmd = (t_cmd*)ft_secu_malloc_lvl(sizeof(t_cmd), 2)))
		sh_exit_error("Malloc Error");
	ft_bzero(*cmd, sizeof(t_cmd));
	if (!((*cmd)->av =
					(char **)secu_malloc(sizeof(char **) * (end - start + 2))))
		sh_exit_error("Malloc Error");
	return (true);
}

/*
** @brief Creates and allocates a new `cmd` struct
**
** @param expands Contains the expanded user input in a token array form
** @param start This is the position of the first token to merge
** @param end This is the position of the last token to merge
** @param type Contains the type of the current token
**
** @return Returns a newly allocated and filled `t_cmd` struct if everything
** went fine. Otherwise, `NULL` will be returned.
*/

t_cmd			*ast_new_cmd(t_array *expands, ssize_t start, ssize_t end,
								t_token_type type)
{
	t_cmd	*cmd;
	t_exp	*exp;
	int		i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (!ast_new_init(expands, start, end, &cmd))
		return (NULL);
	cmd->type = type;
	while (i < (end - start) &&
			(exp = (t_exp*)array_get_at(expands, (size_t)start + i)))
	{
		if (exp->str && exp->type != E_TOKEN_BLANK &&\
				!(type == E_TOKEN_WORD &&
				ast_is_redir(expands, (size_t)start + i, exp->type)))
			cmd->av[cnt++] = exp->str->s;
		i++;
	}
	cmd->av[cnt] = NULL;
	ft_bzero((void *)&cmd->info, sizeof(t_info));
	return (cmd);
}
