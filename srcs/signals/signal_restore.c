/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_restore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:41:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/27 13:41:30 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals/signals.h>

static struct sigaction	*signal_get_old(void)
{
	static struct sigaction	old[32];

	return (old);
}

void					signal_save_old(struct sigaction save, int sig)
{
	struct sigaction	*old;

	if (sig <= 0 || sig >= 32)
		return ;
	old = signal_get_old();
	ft_memcpy(&(old[sig]), &save, sizeof(save));
}

void					signal_restore(void)
{
	int					i;
	struct sigaction	*old;

	i = 0;
	old = signal_get_old();
	log_info("SIGNAL: restore old");
	while (++i <= 31)
	{
		if (i == SIGKILL || i == SIGSTOP || i == SIGTSTP || i == SIGCONT)
			continue ;
		if (sigaction(i, &(old[i]), NULL) == -1)
			log_warn("Signal: can't change restore signal: %d", i);
	}
}
