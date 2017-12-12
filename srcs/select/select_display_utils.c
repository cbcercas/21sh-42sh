/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:54:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/16 23:54:35 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/select.h>
#include <sys/stat.h>

static void	display_set_color(t_sel_word *word)
{
	if (word->st_mode & S_IFDIR)
		ft_putstr_fd("\x1b[91m", STDIN_FILENO);
	else if (word->st_mode & S_IFLNK)
		ft_putstr_fd("\x1b[0m", STDIN_FILENO);
	else if (word->st_mode & S_IFSOCK)
		ft_putstr_fd("\x1b[32m", STDIN_FILENO);
	else if (word->st_mode & S_IFIFO)
		ft_putstr_fd("\x1b[33m", STDIN_FILENO);
	else if (word->st_mode & S_IXUSR)
		ft_putstr_fd("\x1b[92m", STDIN_FILENO);
	else if (word->st_mode & S_IFBLK)
		ft_putstr_fd("\x1b[34;46m", STDIN_FILENO);
	else if (word->st_mode & S_IFCHR)
		ft_putstr_fd("\x1b[34;43m", STDIN_FILENO);
	else if (word->st_mode & S_ISUID)
		ft_putstr_fd("\x1b[30;41m", STDIN_FILENO);
	else if (word->st_mode & S_ISGID)
		ft_putstr_fd("\x1b[30;46m", STDIN_FILENO);
	else if (word->st_mode & S_IWOTH)
		ft_putstr_fd((word->st_mode & S_ISVTX) ? "\x1b[30;42m" : "\x1b[30;33m",
																STDIN_FILENO);
	else
		ft_putstr_fd("\x1b[0m", STDIN_FILENO);
}

void		display_print_word(t_sel_word *word)
{
	t_sel_data	*data;

	if (!(data = select_get_data()))
		return ;
	if (data->options.color)
		display_set_color(word);
	if (data->options.selectable > 1 && word->select)
		tcaps_video_reverse();
	if (word->cursor)
	{
		if (data->options.selectable == 1)
			tcaps_video_reverse();
		else
			tcaps_video_underline(true);
	}
	ft_putstr_fd(word->word, STDIN_FILENO);
}
