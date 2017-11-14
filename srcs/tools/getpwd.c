/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>


char	*get_pwd(void)
{
	char	*pwd;
	struct stat	bufstat;

	pwd = get_var_value(get_envs(), "PWD");
	if (!pwd || *pwd != '/')
		return (NULL);
	if (!stat(pwd, &bufstat) && !lstat(pwd, &bufstat))
		return(ft_strdup(pwd));
	pwd = getcwd(NULL, 0);
	return (pwd);
}