/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history_acdws.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:53:12 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 19:21:01 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_history.h>


void	sh_history_builtin_a(char *str)
{
	t_array	*hists;
	t_hist	*h;
	int		fd;
	size_t	i;

	i = 0;
	if ((fd = open(history_get_path(str), O_RDWR | O_CREAT | O_APPEND, 0644))\
			== -1)
	{
		log_warn("History: History was not save no open");
		ft_putstr_fd("History was not save", 2);
		return ;
	}
	if ((hists = sh_history_get()) == NULL)
		return ;
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		if (h->session == true)
			ft_dprintf(fd, "%s\n", h->cmd);
		i++;
	}
	sh_history_var_session_reset();
}

void	sh_history_builtin_c(void)
{
	t_array		*hist;

	ft_printf("clear history\n");
	hist = sh_history_get();
	while (hist && hist->used)
		hist = array_pop(hist, NULL);
}

void	sh_history_builtin_d(const char *arg)
{
	int			nb;
	t_array		*hists;

	nb = -1;
	hists = sh_history_get();
	if (ft_isdigit(arg[0]))
		nb = atoi(arg) - 1;
	if (nb == -1 || array_remove_at(hists, nb, NULL) == NULL)
		ft_printf("%s: history: %s: history position out of range\n", PROGNAME, arg);
}

void	sh_history_builtin_w(char *path)
{
	t_array	*hists;
	t_hist	*h;
	int		fd;
	size_t	i;

	i = 0;
	if ((fd = open(history_get_path(path), O_RDWR | O_CREAT, 0644)) == -1)
	{
		log_warn("History: History was not save no open");
		ft_putstr_fd("History was not save", 2);
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
	while (argv[index] && ft_isalnum(argv[index][0]))
	{
		if (cmd_join)
			cmd_join = ft_strjoincl(cmd_join, " ", 1);
		cmd_join = ft_strjoincl(cmd_join, argv[index], 1);
		index++;
	}
	if (cmd_join)
	{
		sh_history_set_new(&cmd_join);
	}
}
