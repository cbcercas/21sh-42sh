/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:25:01 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/10 10:05:30 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/prompt.h>

size_t get_prompt(BOOL print)
{
	char		*path;
	char		*tmp;
	size_t	len;

	path = NULL;
	(tmp = sh_getenv_value("USER")) ? 0 : (tmp = "???");
	print ? ft_printf("\033[34m[%s] \033[0m", tmp) : 0;
	len = (ft_strlen(tmp) + 3);
	path = getcwd(path, 0);
	tmp = (path ? ft_strrchr(path, '/') : NULL);
	if (print && tmp && tmp[1])
		ft_printf("\033[93m➜  %s\033[0m$> ", &tmp[1]);
	else if (print && tmp)
		ft_printf("\033[93m➜  %s\033[0m $> ", tmp);
	else if (print)
		ft_printf("\033[93m➜ \033[0m $> ");
	len += (tmp ? ft_strlen(tmp) + 6 : 6);
	ft_strdel(&path);
	return (len);
}

void	sh_print_prompt(void)
{
	get_prompt(true);
}

size_t sh_len_prompt(void)
{
	return (get_prompt(false));
}
