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

int	sh_chdir(t_sh_data *data, char **arg)
{
	(void)data;
	char cwd[1024];
	char *tmp;

	log_dbg3("ici");
	//ft_printf("%s %s", arg[0], arg[1]);
	log_dbg3("ici");
	if ((arg[0] == "-P") || (arg[0] == "-L"))
	{
		log_dbg3("ici");
		ft_printf("-P ou -L detecte");
		log_dbg3("ici");
		if (arg[1] == NULL)
		{
			log_dbg3("ici");
			ft_dprintf(1, "cd: error, option requires an argument");
			log_dbg3("ici");
			return (1);
		}
		else
		{
			log_dbg3("ici");
			//ft_printf("ARG 1: '%s'\nARG 2: '%s'\n", arg[0], arg[1]);
			log_dbg3("ici");
			return (0);
		}
	}
	else
	{
		log_dbg3("ici");
		ft_printf("normal\n");
		log_dbg3("ici");
		return (0);
	}
	log_dbg3("ici");
	/*if (arg == NULL)
	{
		sh_setenv("OLDPWD", sh_getenv_value("PWD"));
		if (chdir(sh_getenv_value("HOME")) == -1)
			ft_printf("cd: HOME not set\n");
	}
	else if (ft_strcmp(arg, "-") == 0)
	{
		tmp = sh_getenv_value("PWD");
		chdir(sh_getenv_value("OLDPWD"));
		sh_setenv("OLDPWD", tmp);
	}
	else
	{
		sh_setenv("OLDPWD", sh_getenv_value("PWD"));
		if (chdir(arg) == -1)
			ft_printf("cd: no such file or directory: %s\n", arg);
	}
	getcwd(cwd, sizeof(cwd));
	sh_setenv("PWD", cwd);
	ft_printf("Current directory: %s\n", cwd);
	return (0);*/
}