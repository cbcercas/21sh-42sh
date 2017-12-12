/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:45:03 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/19 15:00:54 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_history.h>
#include <core/color.h>

/*
** @brief Prints the history
**
** @param nb Number of entries to print (? TODO CHECK)
*/

void	sh_history_builtin_print2(int nb)
{
	BOOL	col;
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	col = get_data(NULL)->opts.color;
	hists = sh_history_get();
	i = (nb > 0 ? hists->used - nb : hists->used);
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		if (get_data(NULL) && get_data(NULL)->opts.color)
			ft_printf("%s %zu %s %s\n", (col) ? C_MAGENTA : "", i + 1,
																C_NONE, h->cmd);
		else
			ft_printf("%zu %s\n", i + 1, h->cmd);
		i++;
	}
}

/*
** @brief Prints the history
**
** @param arg Arguments passed to history
*/

void	sh_history_builtin_print(const char *arg)
{
	int		nb;

	if (!arg)
	{
		sh_history_print();
		return ;
	}
	else if (ft_isdigit(arg[0]) || (arg[0] == '+' && ft_isdigit(arg[1])))
		nb = ft_atoi(arg);
	else
	{
		ft_printf("%s: history: %s: numeric argument required\n", PROGNAME,
				arg);
		return ;
	}
	sh_history_builtin_print2(nb);
}
