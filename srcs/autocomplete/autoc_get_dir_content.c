/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get_dir_content.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:35 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/19 10:01:19 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>


t_array *autoc_get_dir_content(char *path)
{
	t_array *content;

	content = array_create(sizeof(char *));
	DIR *dp;
	struct dirent *ep;

	dp = opendir(path);
	if (dp != NULL)
	{
		while ((ep = readdir(dp)))
			autoc_add_to_array(ep->d_name, content);
		(void) closedir(dp);
	}
	else
	{
		;//TODO ERROR HANDLInG HERE
	}
	return (content);
}