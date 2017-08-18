/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/19 10:01:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <autocomplete/autocomplete.h>
#include <dirent.h>

size_t		ft_strarray_len(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		i = i + 1;
	return (i);
}

t_array *autoc_get_binaries(void)
{
	t_array *binaries;
	char **paths;
	size_t nb_paths;
	size_t  i;
	DIR *dp;
	struct dirent *ep;

	binaries = array_create(sizeof(char *));
	paths = ft_strsplit(getenv("PATH"), ':');
	nb_paths = ft_strarray_len(paths);
	i = 0;
	while (i < nb_paths)
	{
		dp = opendir(paths[i]);
		if (dp != NULL)
		{
			while ((ep = readdir(dp)))
				autoc_add_to_array(ep->d_name, binaries);
			(void)closedir(dp);
		}
		else
		{
			;//TODO ERROR HANDLInG HERE
		}
		i++;
	}
	return (binaries);
}
