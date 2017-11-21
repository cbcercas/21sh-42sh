/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:02:55 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:03:17 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_pwd.h>

extern int			g_optind;

/*
** @brief Prints the pwd usage
** @return Returns 1
*/

static int			pwd_usage(void)
{
	ft_putendl_fd("usage: pwd [-L | -P]", STDERR_FILENO);
	return (1);
}

/*
** @brief TODO
** @param pwd_err TODO
** @return TODO
*/

static char			*getcwd_logical(BOOL *pwd_err)
{
	struct stat	lg;
	struct stat	phy;
	char		*pwd;

	if ((pwd = get_var_value(get_envs(), "PWD")) != NULL && *pwd == '/')
	{
		if (stat(pwd, &lg) == -1 || stat(".", &phy) == -1)
			return (NULL);
		if (lg.st_dev == phy.st_dev && lg.st_ino == phy.st_ino)
			return (pwd);
	}
	*pwd_err = true;
	return (NULL);
}

/*
** @brief Prints the pwd if everything is ok
** @param physical Is the pwd from a function or from the env
** @return Returns a ret value
*/

static int			do_builtin_pwd(BOOL physical)
{
	BOOL	pwd_err;
	char	*pwd;

	pwd_err = false;
	if ((!physical && (pwd = getcwd_logical(&pwd_err))) ||
		((physical || pwd_err == 1) && (pwd = getcwd(NULL, 0))))
		ft_putendl(pwd);
	else
	{
		ft_putendl("No such file or directory: .");
		return (1);
	}
	if ((physical || pwd_err == 1))
		ft_strdel(&pwd);
	return (0);
}

/*
** @brief Main functions for the pwd builtin
** @param data The shell's data used across the program
** @param argv The args passed to pwd
** @return Returns a ret value based on its success or not
*/

int					sh_builtin_pwd(t_sh_data *data, char **argv)
{
	BOOL	physical;
	int		ch;

	(void)data;
	ft_getopt_reset();
	physical = false;
	while ((ch = ft_getopt(ft_tablen(argv), argv, "LPh")) != -1)
	{
		if (ch == 'L')
		{
			physical = false;
			break ;
		}
		else if (ch == 'P')
		{
			physical = true;
			break ;
		}
		else
			return (pwd_usage());
	}
	if (argv[g_optind])
		return (pwd_usage());
	return (do_builtin_pwd(physical));
}
