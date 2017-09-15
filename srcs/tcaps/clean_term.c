/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:33:54 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/15 16:34:23 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

void clean_term(void)
{
	unsigned int		nb_of_ligne;
	t_ts						ts;

	ts = get_term_size();
	tputs(tgetstr("sc", NULL), 0, &ft_putchar2);
		ft_printf("\n");
	nb_of_ligne = ts.ts_cols;
	while(nb_of_ligne)
	{
		tputs(tgetstr("cr", NULL), 0, &ft_putchar2);
		tputs(tgetstr("cd", NULL), 0, &ft_putchar2);
		nb_of_ligne--;
	}
	tputs(tgetstr("rc", NULL), 0, &ft_putchar2);
}
