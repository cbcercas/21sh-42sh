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

/*
** @brief TODO
** @param nb TODO
*/

void	sh_history_builtin_print2(int nb)
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	hists = sh_history_get();
	i = (nb > 0 ? hists->used - nb : hists->used);
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		ft_printf("%zu %s\n", i + 1, h->cmd);
		i++;
	}
}

/*
** @brief Prints the history
** @param arg TODO
*/

void	sh_history_builtin_print(const char *arg)
{
	int		nb;

	nb = 0;
	if (!arg)
	{
		sh_history_print();
		return ;
	}
	else if (ft_isdigit(arg[0]) || (arg[0] == '+' && ft_isdigit(arg[1])))
		nb = ft_atoi(arg);
	else
	{
		ft_printf("bash: history: %s: numeric argument required\n", arg);
		return ;
	}
	sh_history_builtin_print2(nb);
}
