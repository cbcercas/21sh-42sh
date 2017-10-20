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
#include <environ/builtin_env_utils.h>
#include <tools/tools.h>
#include <ft_secu_malloc/ft_secu_malloc.h>
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

/*int sh_history_open_fd(char *path, int flag)
{
	struct stat			type;
	int							fd;

	fd = -1;
	if(!flag)
		return (-1);
	if(!path)
		path = HISTORY_FILE;
	if (stat("/tmp", &type) == -1 || !S_ISDIR(type.st_mode))
	{
		log_warn("History: stat \"tmp\" fail");
		return (-1);
	}
	if ((fd = open(path, flag, 0644)) == -1)
	{
		log_warn("History: open \"%s\" fail", path);
		return (-1);
	}
	return (fd);
}*/

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

t_array		*sh_history_init()
{
	t_array	*hists;
	t_hist	*h;
	char		*line;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = open(history_get_path(NULL), O_RDWR | O_CREAT, 0644)) == -1)
		return (NULL);
	if ((hists = sh_history_get()) != NULL)
	{
		while (get_next_line(fd, &line) && i < 1000)
		{
				if ((h = sh_history_new(line)))
				{
					h->session = false;
					array_push(hists, (void *)h);
					ft_memdel((void **) &h);
				}
				i++;
		}
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
