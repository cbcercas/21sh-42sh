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
#include <tools/tools.h>
#include <environ/getter_env.h>
#include <environ/builtin_env_utils.h>

//TODO check if PATH is in envs or in local var
static void		autocomplete_push_one(t_array *content, struct dirent *file,\
											char *begin, char **env_path)
{
	t_string		*tmp;
	char			*path;

	tmp = NULL;
	path = NULL;
	if (!autocomplete_is_dots(file->d_name) &&\
			sh_test_access((path = makefilepath(*env_path, file->d_name))) != -1 &&\
				(!begin || ft_strnequ(begin, file->d_name, ft_strlen(begin))))
	{
		tmp = string_dup_secu(file->d_name, M_LVL_AUTOC);
		array_push(content, (void *)tmp);
	}
	ft_strdel(&path);
}

t_array	*autocomplete_get_bin(char *begin)
{
	t_array			*content;
	DIR				*dir;
	struct dirent	*file;
	char			**env_path;

	content = array_create(sizeof(t_string));
	env_path = ft_strsplit_secu(get_var_value(get_envs(), "PATH"), ':', M_LVL_AUTOC);
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
	return (content);
}
