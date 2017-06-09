/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:40:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/08 17:21:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <history/history.h>

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

int sh_history_open_fd(char *path, int flag)
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
}

t_array		*sh_history_init(char *path)
{
	t_array	*hists;
	t_hist	*h;
	char		*line;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd(path, O_RDWR | O_CREAT)) == -1)
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
		}
	}
	close(fd);
	return (hists);
}

void	sh_history_save()
{
	t_array	*hists;
	t_hist	*h;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd(NULL, O_RDWR | O_CREAT | O_APPEND)) == -1)
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
		sh_history_print_in_log();
		array_destroy(&hists, sh_history_del);
		close(fd);
}
