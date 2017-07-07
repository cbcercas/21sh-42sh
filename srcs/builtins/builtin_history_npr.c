/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history_npr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 09:29:56 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/19 14:59:51 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_history.h>

void		sh_history_builtin_r(char *path)
{
	t_array	*hists;
	t_hist	*h;
	char	*line;
	int		fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd(path, O_RDWR | O_CREAT)) == -1)
		return ;
	if ((hists = sh_history_get()) != NULL)
	{
		while (get_next_line(fd, &line) && i < 1000)
		{
			if ((h = sh_history_new(line)))
			{
				h->session = true;
				array_push(hists, (void *)h);
				ft_memdel((void **)&h);
			}
			i++;
		}
	}
	close(fd);
	return ;
}

void		sh_history_builtin_n(char *path)
{
	t_array	*hists;
	t_hist	*h;
	char	*line;
	int		fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd(path, O_RDWR | O_CREAT)) == -1)
		return ;
	if ((hists = sh_history_get()) != NULL)
	{
		while (get_next_line(fd, &line) && i < 1000)
		{
			if (i >= hists->used && (h = sh_history_new(line)))
			{
				h->session = true;
				array_push(hists, (void *)h);
				ft_memdel((void **)&h);
			}
			i++;
		}
	}
	close(fd);
	return ;
}

static void	sh_history_builtin_p_helper(char *result, int index, char **arg)
{
	if (result)
		ft_printf("%s\n", result);
	ft_strdel(&result);
	index = 2;
	while (arg && arg[index])
	{
		ft_printf("%s\n", arg[index]);
		index++;
	}
}

void		sh_history_builtin_p(char **arg)
{
	int		index;
	char	*result;

	index = 0;
	result = NULL;
	array_pop(sh_history_get(), NULL);
	while (arg && arg[index])
	{
		if (arg[index][0] == '!' && arg[index][1])
		{
			ft_strdel(&result);
			ft_printf("%s: event not found\n", arg[index]);
			return ;
		}
		if (result)
			result = ft_strjoincl(result, " ", 1);
		result = ft_strjoincl(result, arg[index], 1);
		index++;
	}
	sh_history_builtin_p_helper(result, index, arg);
	return ;
}
