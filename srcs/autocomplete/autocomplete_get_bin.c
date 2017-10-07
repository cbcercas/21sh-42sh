/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get_bin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 13:37:14 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/04 12:08:07 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

//TODO check if PATH is in envs or in local var
t_array	*autocomplete_get_bin(char *begin)
{
	t_array			*content;
	DIR				*dir;
	struct dirent	*file;
	t_string		*tmp;
	char			**env_path;

	content = array_create(sizeof(t_string));
	env_path = ft_strsplit_secu(get_var_value(get_envs(), "PATH"), ':', M_LVL_AUTOC);
	while (env_path && *env_path && content->used <= 3000)
	{
		if ((dir = opendir(*env_path)) != NULL)
		{
			while ((file = readdir(dir)))
			{
				if (!begin || ft_strnequ(begin, file->d_name, ft_strlen(begin)))
				{
					tmp = string_dup_secu(file->d_name, M_LVL_AUTOC);
					array_push(content, (void *)tmp);
				}
			}
			closedir(dir);
		}
		env_path++;
	}
	return (content);
}
