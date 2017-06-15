/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:34:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/15 11:01:20 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <builtins/chdir.h>

int	sh_chdir(t_sh_data *data, char *arg)
{
	//char	*dir;
	(void)data;

	//dir = sh_extract_str(arg);
	//ft_printf("%s\n", dir);


	char cwd[1024];
	char *tmp;

	if (arg == NULL)
	{
		sh_setenv("OLDPWD", sh_getenv_value("PWD"));
		//*env = ft_setenv("OLDPWD", getcharenv(*env, "PWD"), *env);
		//if (chdir(getcharenv(*env, "HOME")) == -1)
		if (chdir(sh_getenv_value("HOME")) == -1)
			ft_printf("cd: HOME not set\n");
	}
	else if (ft_strcmp(arg, "-") == 0)
	{
		tmp = sh_getenv_value("PWD");
		//tmp = getcharenv(*env, "PWD");
		chdir(sh_getenv_value("OLDPWD"));
		//chdir(getcharenv(*env, "OLDPWD"));
		sh_setenv("OLDPWD", tmp);
		//*env = ft_setenv("OLDPWD", tmp, *env);
	}
	else
	{
		sh_setenv("OLDPWD", sh_getenv_value("PWD"));
		//*env = ft_setenv("OLDPWD", getcharenv(*env, "PWD"), *env);
		if (chdir(arg) == -1)
			ft_printf("cd: no such file or directory: %s\n", arg);
	}
	getcwd(cwd, sizeof(cwd));
	sh_setenv("PWD", cwd);
	//*env = ft_setenv("PWD", cwd, *env);
	ft_printf("Current directory: %s\n", cwd);
	return (0);
}