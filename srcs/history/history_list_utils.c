/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:00:49 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/05 14:19:02 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

t_hist	*sh_history_new(char *cmd)
{
	t_hist	*h;

	if(sh_history_is_space_plus(cmd))
		return (NULL);
	if ((h = ft_memalloc(sizeof(*h))) == NULL)
	{
		log_fatal("History: can't create new history command");
		ft_dprintf(STDERR_FILENO,"History: can't create new history command");
	}
	else if ((h->cmd = cmd) == NULL)
	{
		log_fatal("History: can't create new history command");
		ft_dprintf(STDERR_FILENO,"History: can't create new history command");
		ft_memdel((void**)&h);
	}
	h->buf = NULL;
	h->cur = -1;
	return (h);
}

void sh_history_del(void *i)
{
	t_hist *h;

	h = (t_hist *)i;
	if (h->cmd)
		ft_strdel(&(h->cmd));
	if (h->buf)
		ft_strdel(&(h->buf));
}
