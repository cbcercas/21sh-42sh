/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:40:23 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/03 16:50:58 by gpouyat          ###   ########.fr       */
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

int sh_history_open_fd(void)
{
	struct stat			type;
	int							fd;

	fd = -1;
	if (stat("/tmp", &type) == -1 || !S_ISDIR(type.st_mode))
	{
		log_warn("History: stat \"tmp\" fail");
		return (-1);
	}
	if ((fd = open("/tmp/.21sh_history", O_RDWR | O_CREAT, 0644)) == -1)
	{
		log_warn("History: open \"/tmp/.21sh_history\" fail");
		return (-1);
	}
	return (fd);
}

t_array		*sh_history_init(void)
{
	t_array	*hists;
	t_hist	*h;
	char		*line;
	int			fd;
	size_t	i;

	i = 0;
	if ((fd = sh_history_open_fd()) == -1)
		return (NULL);
	if ((hists = sh_history_get()) != NULL)
	{
		while (get_next_line(fd, &line) && i < 1000)
		{
				if ((h = sh_history_new(line)))
				{
					array_push(hists, (void *)h);
					ft_memdel((void **) &h);
				}
		}
	}
	close(fd);
	//sh_history_print();
	return (hists);
}


void sh_history_print()
{
	t_array	*hists;
	t_hist	*h;
	size_t	i;

	hists = sh_history_get();
	i = 0;
	while (i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		ft_printf("%zu %s\n", i, h->cmd);
		i++;
	}
}
