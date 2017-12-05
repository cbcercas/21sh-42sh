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

#include <history/history.h>

/*
** @brief Gets the history stored in a t_array form
** @return The t_array containing the history
*/

t_array		*sh_history_get(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(t_hist))) == NULL)
		{
			log_fatal("Environ: can't initialise history array");
			ft_dprintf(STDERR_FILENO, "Environ: can't initialise hsitory");
			exit(EXIT_FAILURE);
		}
	}
	return (e);
}

/*
** @brief Creates a string that contains the history file location
**
** @param str The history file name
**
** @return Returns a full absolute path to the history file
*/

char		*history_get_path(char *str)
{
	char		*home;
	static char	ret[PATH_MAX];

	if (str)
		return (str);
	if (!(home = get_var_value(get_envs(), "HOME")))
		return (NULL);
	ft_bzero(ret, PATH_MAX);
	if ((ft_strlen(home) + ft_strlen(HISTORY_FILE) + 2) >= PATH_MAX)
		return (NULL);
	ft_strlcat(ret, home, PATH_MAX);
	ft_strlcat(ret, "/", PATH_MAX);
	ft_strlcat(ret, HISTORY_FILE, PATH_MAX);
	return (ret);
}

static	int	history_get_fd(void)
{
	int		fd;
	char	*path;

	fd = -1;
	if (!(path = history_get_path(NULL)))
		return (fd);
	if (get_history_init_choice(-1) != 5 && get_history_init_choice(-1) != -1)
		open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if ((fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644)) == -1)
	{
		log_warn("History: History was not saved, Failed open");
		default_terminal_mode();
		ft_putstr_fd("\nHistory wasn't saved\n", 2);
		raw_terminal_mode();
		return (fd);
	}
	return (fd);
}

/*
** @brief Saves the history when the programs exists
*/

void		sh_history_save(void)
{
	t_array	*hists;
	t_hist	*h;
	int		fd;
	size_t	i;

	i = 0;
	fd = history_get_fd();
	if ((hists = sh_history_get()) == NULL)
		return ;
	while (fd != -1 && i < hists->used)
	{
		h = (t_hist *)array_get_at(hists, i);
		if (h && h->session == true)
			ft_dprintf(fd, "%s\n", h->cmd);
		i++;
	}
	sh_history_print_in_log();
	array_destroy(&hists, sh_history_del);
	if (fd != -1)
		close(fd);
}
