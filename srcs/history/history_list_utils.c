/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:00:49 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/16 21:04:25 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

/*
** @brief Adds a new entry from command `cmd` into the `t_hist history`
**
** @param cmd The command to be added into the history
**
** @return Returns a t_hist containing the `cmd`
*/

t_hist	*sh_history_new(char *cmd)
{
	t_hist	*h;

	if (sh_history_is_space_plus(cmd) || !is_printstr(cmd))
		return (NULL);
	if ((h = ft_memalloc(sizeof(*h))) == NULL)
		sh_exit_error("History: can't create new history command");
	else if ((h->cmd = (const char *)cmd) == NULL)
		sh_exit_error("History: can't create new history command");
	h->cur = -1;
	return (h);
}

/*
** @brief Deletes a history entry
**
** @param i The entry to be destroyed
*/

void	sh_history_del(void *i)
{
	t_hist *h;

	h = (t_hist *)i;
	if (h->cmd)
		ft_strdel((char **)&(h->cmd));
}

/*
** @brief Resets all the parameters and sets the session param to false
** When set to false, the session param means that the history entry is loaded
** from the file and not from the current shell session
*/

void	sh_history_var_session_reset(void)
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	i = 0;
	if ((hists = sh_history_get()) == NULL)
		return ;
	while (i < hists->used && (h = (t_hist *)array_get_at(hists, i)))
	{
		h->session = false;
		i++;
	}
}

void	*sh_history_remove_at(size_t nb)
{
	t_hist		*h;
	t_array		*hists;

	hists = sh_history_get();
	if (!hists)
		return (NULL);
	h = (t_hist *)array_get_at(hists, (size_t)nb);
	if (h)
		ft_strdel((char **)(&(h->cmd)));
	return (array_remove_at(hists, nb, NULL));
}
