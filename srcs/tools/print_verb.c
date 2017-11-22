/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_verb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:00:51 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 19:00:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>
#include <core/data.h>
#include <core/color.h>

void print_verb(char *line)
{
	char	*tmp;

	if (!line || !get_data(NULL) || !get_data(NULL)->opts.verbose
		|| !ft_strlen(line))
		return ;
	tmp = ft_strrchr(line, '\n');
	if (get_data(NULL)->opts.color)
		ft_putstr(C_RED);
	if (tmp && tmp[1])
		ft_putendl_fd(&tmp[1], STDIN_FILENO);
	else if (tmp)
		ft_putstr_fd(tmp, STDIN_FILENO);
	else
		ft_putendl_fd(line, STDIN_FILENO);
	if (get_data(NULL)->opts.color)
		ft_putstr(C_NONE);
}
