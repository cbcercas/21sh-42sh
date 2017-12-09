/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get_bin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 13:37:14 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 16:50:28 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

static void		autocomplete_push_one(t_array *content, struct dirent *file,\
											char *begin, char **env_path)
{
	t_string		*tmp;
	char			*path;

	path = NULL;
	if (!autocomplete_is_dots(file->d_name) &&\
			!sh_test_access((path = makefilepath(*env_path, file->d_name))) &&\
				(!begin || ft_strnequ(begin, file->d_name, ft_strlen(begin))))
	{
		if (!(content->used == content->capacity && !array_growth(content)))
		{
			tmp = array_get_at(content, content->used);
			if (string_insert_front(tmp, file->d_name))
				content->used += 1;
			else
				sh_exit_error("Malloc Error");
		}
	}
	ft_strdel(&path);
}

t_array	*autocomplete_get_bin(char *begin)
{
	t_array			*content;
	DIR				*dir;
	struct dirent	*file;
	char			**env_path;

	if (!(content = array_create(sizeof(t_string))))
		return (NULL);
	if (!(env_path = ft_strsplit(get_var_value(get_envs(), "PATH"), ':')))
		env_path = ft_strsplit(get_var_value(get_vars(), "PATH"), ':');
	while (env_path && *env_path && content->used <= 3000)
	{
		if ((dir = opendir(*env_path)) != NULL)
		{
			while ((file = readdir(dir)))
				autocomplete_push_one(content, file, begin, env_path);
			closedir(dir);
		}
		env_path++;
	}
	ft_freetab(env_path, ft_tablen(env_path));
	return (content);
}
