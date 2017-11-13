/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:40:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 18:41:47 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>
#include <history/history.h>
#include <logger.h>
#include <ftprintf.h>
#include <environ/getter_env.h>
#include <environ/env_utils.h>
#include <tools/tools.h>
#include <secure_memory/ft_secu_malloc.h>
#include <fcntl.h>
#include <gnl/get_next_line.h>


t_array	*sh_history_get(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(t_hist))) == NULL)
		{
			log_fatal("Environ: can't initialise history array");
			ft_dprintf(STDERR_FILENO, "Environ: can't initialise hsitory");
			exit(1);
		}
	}
	return (e);
}

char	*history_get_path(char *str)
{
	char	*home;

	if (str)
		return (str);
	if(!(home = get_var_value(get_envs(), "HOME")))
		return (NULL);
	home = ft_strjoincl_secu(home, "/", 0, M_LVL_FUNCT);
	return (ft_strjoincl_secu(home, HISTORY_FILE, 1, M_LVL_FUNCT));
}

void	sh_history_init_one(t_array *hists, int fd)
{
	t_hist	*h;
	char	*line;
	char	*cmd;

	cmd = NULL;
	line = NULL;
	while (get_next_line(fd, &line) && line && ft_strlen(line) > 0 &&
		   (line[ft_strlen(line) - 1] == '\\'))
	{
		if (cmd)
			cmd = ft_strjoincl(cmd, "\n", 1);
		cmd = ft_strjoincl(cmd, line, 3);
	}
	if (cmd && line)
		cmd = ft_strjoincl(cmd, "\n", 1);
	cmd = ft_strjoincl(cmd, line, 3);
	if ((h = sh_history_new(cmd)))
	{
		h->session = false;
		array_push(hists, (void *) h);
		ft_memdel((void **) &h);
	}
}

t_array *sh_history_init(t_array *hists)
{
	int			fd;
	size_t	i;

	i = 0;
	if (!(hists = sh_history_get()))
		return (NULL);
	if ((fd = open(history_get_path(NULL), O_RDWR | O_CREAT, 0644)) == -1)
		return (NULL);
	while (i < 1000)
	{
		sh_history_init_one(hists, fd);
		i++;
	}
	close(fd);
	return (hists);
}

void	sh_history_save(void)
{
	t_array	*hists;
	t_hist	*h;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = open(history_get_path(NULL), O_RDWR | O_CREAT | O_APPEND, 0644)) == -1)
	{
		log_warn("History: History was not save FAIL open");
		ft_putstr_fd("\nHistory was not save", 2);
		return ;
	}
	if ((hists = sh_history_get()) == NULL)
		return ;
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		if(h && h->session == true)
			ft_dprintf(fd, "%s\n", h->cmd);
		i++;
	}
	sh_history_print_in_log();
	array_destroy(&hists, sh_history_del);
	close(fd);
}

const char 	*history_get_n(size_t n)
{
	t_array	*hists;
	t_hist	*h;

	hists = sh_history_get();
	if (!hists || (n >= hists->used))
		return (NULL);
	if (!(h = (t_hist *)array_get_at(hists, hists->used - n - 1)))
		return (NULL);
	return (h->cmd);
}