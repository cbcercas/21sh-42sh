/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:00:49 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/03 16:42:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history_list_utils.h>

t_hist	*sh_history_new(char *cmd)
{
	t_hist	*h;

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
	h->cur = 0;
	return (h);
}
