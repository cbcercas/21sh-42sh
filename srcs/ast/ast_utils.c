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
#include <builtins/builtin_exit.h>

/*
** @brief Frees cmd content and cmd
**
** @param cmd the cmd to be freed and deleted
**
** @return void
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
	cmd = NULL;
}

/*
** @brief Displays content of cmd
**
** @param cmd Command struct containing cmd to be displayed
**
** @return Returns "" or NULL.
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
** @brief Searches for the next token with greater priority (?TODO gpouyat)
**
** @param expands Contains the token array
** @param prio Priority for tokens
**
** 1 = ";" or "||" or "&&",\n
** 2 = "|",\n
** 3 = redirections,\n
** 4 = "&".
** @param lim Contains the virtual limit
**
** @return Returns token or NULL.
*/

t_exp			*ast_search(t_array *expands, t_lim *lim, int prio)
{
	t_exp		*exp;

	exp = NULL;
	while (lim->cnt < lim->lim && lim->cnt <= expands->used &&\
			(!exp || !(ast_prio(exp->type, prio, lim->cnt - 1, expands))))
	{
		exp = (t_exp *)array_get_at(expands, lim->cnt);
		lim->cnt++;
	}
	return (exp);
}


/*
** @brief malloc cmd and cmd->av for ast_new_cmd()
**
** @param expands is token arrays
** @param start is positon of first token
** @param end is positon of last token
** @param cmd is the struc of command
**
** @return If an error has occurred, a value of false is returned
*/

static BOOL		ast_new_init(t_array *expands, int start, int end,
								t_cmd **cmd)
{
	if ((end - start) < 0)
		return (false);
	if (!expands || !(*cmd = (t_cmd*)ft_secu_malloc_lvl(sizeof(t_cmd), 2)))
		sh_exit(NULL, NULL);
	ft_bzero(*cmd, sizeof(t_cmd));
	if (!((*cmd)->av =
				  (char **)secu_malloc(sizeof(char **) * (end - start + 2))))
		sh_exit(NULL, NULL);
	return (true);
}

/*
** @brief Creates and allocates a new cmd struct
**
** @param expands Contains the token array
** @param start Contains position of the first token
** @param end Contains position of the last token
** @param type Contains the type of current token
**
** @return Returns new cmd or NULL TODO NORM HERE
*/

t_cmd			*ast_new_cmd(t_array *expands, int start, int end,\
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
			(exp = (t_exp*)array_get_at(expands, start + i)))
	{
		if (exp->str && exp->type != E_TOKEN_BLANK &&\
				!(type == E_TOKEN_WORD &&
				ast_is_redir(expands, start + i, exp->type)))
			cmd->av[cnt++] = exp->str->s;
		i++;
	}
	cmd->av[cnt] = NULL;
	ft_bzero((void *)&cmd->info, sizeof(t_info));
	return (cmd);
}
