/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:28:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/20 16:14:17 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <history/history.h>

int		sh_history_init_one(t_array *hists, int fd)
{
	t_hist	*h;
	char	*line;
	char	*cmd;
	int		ret;

	cmd = NULL;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) && line && ft_strlen(line) > 0
		   && (line[ft_strlen(line) - 1] == '\\'))
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
	return (ret);
}

int		get_history_init_choice(int choice)
{
	static int save_choice = -1;

	if (choice <= 5 && choice >= 1)
		save_choice = choice;
	return (save_choice);
}

void	sh_history_print_choice(int limit)
{
	ft_dprintf(STDERR_FILENO, "%s: The history file is too big (%d/%d bytes)\n"
			"\t (1): Delete and create a new one\n"
			"\t (2): Save the file somewhere and create a new file\n\n"
			"\t ### DANGEROUS CHOICES ###\n"
			"\t (3): Force load, save the current file and create a new one\n"
			"\t (4): Force load and delete\n \t (5): Force load\n\n"
			"\t (?): Default: (1)\n", PROGNAME, limit, HISTORY_FILE_MAX);
}

int		sh_history_init_choice(int fd, int limit)
{
	char *line;

	line = NULL;
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
		return (open(history_get_path(NULL), O_RDWR | O_CREAT | O_TRUNC, 0644));
	sh_history_print_choice(limit);
	ft_putstr(">");
	get_next_line(0, &line);
	get_history_init_choice(ft_atoi(line));
	if (ft_strequ(line, "2") || ft_strequ(line, "3"))
	{
		while (42)
		{
			ft_strdel(&line);
			ft_putstr("Ppath ? (q == exit): ");
			get_next_line(0, &line);
			if (ft_strequ(line, "q") || !rename(history_get_path(NULL), line)) // fonctions interdites mais man 2 + on gère la save de l'history
				break ;
			ft_putstr("This path doesn't exists\n");
		}
	}
	ft_strdel(&line);
	if (get_history_init_choice(-1) <= 3)
		return (open(history_get_path(NULL), O_RDWR | O_CREAT | O_TRUNC, 0644));
	return (fd);
}

t_array *sh_history_init(t_array *hists)
{
	int			fd;
	struct stat bufstat;

	if (!(hists = sh_history_get()))
		return (NULL);
	if ((fd = open(history_get_path(NULL), O_RDWR | O_CREAT, 0644)) == -1)
		return (NULL);
	if (stat(history_get_path(NULL), &bufstat))
		return (NULL);
	if (bufstat.st_size >= HISTORY_FILE_MAX)
		fd = sh_history_init_choice(fd, bufstat.st_size);
	if (fd == -1)
		return (NULL);
	log_dbg3("HISTORY init: choice = %d", get_history_init_choice(-1));
	while (sh_history_init_one(hists, fd))
	{
		if (hists->used >= HISTORY_MAX)
			array_remove_at(hists, 0, NULL);
	}
	close(fd);
	return (hists);
}