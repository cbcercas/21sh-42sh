/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:22:15 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/10 08:49:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

void sh_history_print()
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	hists = sh_history_get();
	i = 0;
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		ft_printf("%zu %s\n", i + 1 , h->cmd);
		i++;
	}
}

void sh_history_print_in_log(void)
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;
	int		ses;

	hists = sh_history_get();
	i = 0;
	log_dbg1("***********HISTORY PRINT**************");
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		ses = (h->session == true ? 1 : 0);
		log_dbg1("%zu %s | %d", i, h->cmd, ses);
		i++;
	}
	log_dbg1("**************************************");
}

void	sh_history_clear_line(unsigned int nb_of_car)
{
	unsigned int		nb_of_ligne;
	t_ts						ts;

	ts = get_term_size();
	nb_of_ligne = ((nb_of_car - 1) / ts.ts_cols) + 1;
	if (nb_of_ligne != 1 && ((((nb_of_car - 1) % ts.ts_cols) == ts.ts_cols) ||
					(((nb_of_car - 1) % ts.ts_cols) == 0)))
		nb_of_ligne--;
	while(nb_of_ligne)
	{
		tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
		tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
		if (nb_of_ligne > 1)
			tputs(tgetstr("up", NULL), 0, &ft_putchar2);
		nb_of_ligne--;
	}
}

void	sh_history_clear_len(char *buff, char *result, BOOL fail)
{
	unsigned int len;

	len = (fail == true ? 32 : 18);
	sh_history_clear_line(len + ft_strlen(buff) + ft_strlen(result));
}