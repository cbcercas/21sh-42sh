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
** \fn void		ast_del_cmd(t_cmd *cmd)
**
** \brief free cmd content and cmd
**
** \param cmd
**
** \return void.
*/
void		ast_del_cmd(t_cmd *cmd)
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
** \fn char		*ast_aff(t_cmd *cmd)
**
** \brief display content of cmd
**
** \param cmd struct command
**
** \return return "" or NULL.
*/
char		*ast_aff(t_cmd *cmd)
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
** \fn t_exp			*ast_search(t_array *expands, t_lim *lim, int prio)
**
** \brief search next token with prio param
**
** \param expands is token arrays
** \param prio 1 = ";" or "||" or "&&", 2 = "|", 3 = redirections, 4 = "&"
** \param lim virtual limit
**
** \return token or NULL.
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
** \fn t_cmd		*ast_new_cmd(t_array *expands, int start, int end,\
**							                           t_token_type type)
**
** \brief creat and malloc a new cmd
**
** \param expands is token arrays
** \param start is positon of first token
** \param end is positon of last token
** \param type is the type of current token
**
** \return new cmd or NULL
*/
t_cmd		*ast_new_cmd(t_array *expands, int start, int end,\
		t_token_type type)
{
	t_cmd	*cmd;
	t_exp	*exp;
	int		i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if ((end - start) < 0)
		return (NULL);
	if (!expands || !(cmd = (t_cmd*)ft_secu_malloc_lvl(sizeof(t_cmd), 2)))
		return (NULL);
	ft_bzero(cmd, sizeof(t_cmd));
	if (!(cmd->av = (char **)secu_malloc(sizeof(char **) * (end - start + 2))))
		return (NULL);
	cmd->type = type;
	while (i < (end - start) && (exp = (t_exp*)array_get_at(expands, start + i)))
	{
		if (exp->str && exp->type != E_TOKEN_BLANK &&\
				!(type == E_TOKEN_WORD && ast_is_redir(expands, start + i, exp->type)))
			cmd->av[cnt++] = exp->str->s;
		i++;
	}
	cmd->av[cnt] = NULL;
	ft_bzero((void *)&cmd->info, sizeof(t_info));
	return (cmd);
}
