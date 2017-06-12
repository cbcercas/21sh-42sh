/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:53:12 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/08 17:50:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_history.h>

void sh_history_builtin_a(char *str)
{
	t_array	*hists;
	t_hist	*h;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd(str,  O_RDWR | O_CREAT | O_APPEND)) == -1)
	{
		log_warn("History: History is not save no open");
		ft_putstr_fd("History is not save", 2);
		return ;
	}
	if ((hists = sh_history_get()) == NULL)
		return ;
		while (i < hists->used)
		{
			h = (t_hist *)array_get_at(hists, i);
			if(h->session == true)
				ft_dprintf(fd, "%s\n", h->cmd);
			i++;
		}
	sh_history_var_session_reset();
}

void	sh_history_builtin_c(void)
{
	t_array		*e;

	ft_printf("clear history\n");
	sh_history_destroy();
	e = sh_history_get();
	if ((e = array_create(sizeof(t_hist))) == NULL)
	{
		log_fatal("Environ: can't initialise history array");
		ft_dprintf(STDERR_FILENO, "Environ: can't initialise hsitory");
		exit(1);
	}
}

void	sh_history_builtin_d(char *arg)
{
	int			nb;
	t_array		*hists;

	nb = -1;
	hists = sh_history_get();
	if (ft_isdigit(arg[0]))
		nb = atoi(arg);
	if (array_remove_at(hists, nb, NULL) == NULL)
		ft_printf("bash: history: %s: history position out of range\n", arg);
}

void	sh_history_builtin_w(char *path)
{
	t_array	*hists;
	t_hist	*h;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd(path, O_RDWR | O_CREAT)) == -1)
	{
		log_warn("History: History is not save no open");
		ft_putstr_fd("History is not save", 2);
		return ;
	}
	if ((hists = sh_history_get()) == NULL)
		return ;
		while (i < hists->used)
		{
			h = (t_hist *)array_get_at(hists, i);
			ft_dprintf(fd, "%s\n", h->cmd);
			i++;
		}
		close(fd);
}

void	sh_history_builtin_s(char **argv, int index)
{
	char *cmd_join;

	cmd_join = NULL;
	while(argv[index] && ft_isalnum(argv[index][0]))
	{
		if(cmd_join)
			cmd_join = ft_strjoincl(cmd_join, " ", 1);
		cmd_join = ft_strjoincl(cmd_join, argv[index], 1);
		index++;
	}
	if(cmd_join)
	{
		sh_history_set_new(cmd_join);
		ft_strdel(&cmd_join);
	}
}
