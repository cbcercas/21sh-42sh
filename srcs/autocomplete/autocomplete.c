/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 16:38:41 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>
#include <dirent.h>
#include <logger.h>

t_array	*autoc_create_array(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(char *))) == NULL)
		{
			log_fatal("Environ: can't initialise autocomplete array");
			ft_dprintf(STDERR_FILENO, "Environ: can't initialise autocomplete");
			exit(1);
		}
	}
	return (e);
}

char *autoc_get_last(char *current_input)
{
	char *last_word;
	size_t input_len;
	size_t i;
	size_t j;

	j = 0;
	input_len = ft_strlen(current_input);
	i = input_len - 1;
	while (ft_isalnum(current_input[i]) == 1)
	{
		j++;
		i--;
	}
	last_word = ft_strsub(current_input, input_len - j, j);
	return (last_word);
}

char **autoc_get_possibilities(char *word)
{
	char **possibilities;

	char *path = getenv("PATH");
	char **path_split = ft_strsplit(path, ':');


	DIR *dp;
	struct dirent *ep;

	dp = opendir (path_split[0]);
	if (dp != NULL)
	{
		while (ep = readdir (dp))
			possibilities = ft_add_to_array(ep->d_name, possibilities);
		(void) closedir (dp);
	}
	else
		ft_printf("Error autocomplete opening directory");
	return (possibilities);
}