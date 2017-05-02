/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/15 11:00:06 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/init.h>

extern char const	*g_optarg;

static void		sh_data_free(t_sh_data *data)
{
	//TODO free envs
	return;
}

void	sh_testing(const char *arg)
{
	if (ft_strequ(arg, "env"))
		sh_testing_env();
	if (ft_strequ(arg, "lexer"))
		sh_testing_lexer();
	else
	{
		ft_dprintf(STDERR_FILENO, "Unknown testing arg.\n");
		sh_help_exit();
	}
}

static void sh_options(t_sh_opt *opts, int ac, char *const *av)
{
	int opt;

	while ((opt = ft_getopt(ac, av, "hvd:t:")) >= 0)
	{
		if (opt == 'v')
			opts->verbose = 1;
		else if (opt == 'd')
			if (ft_atoi(g_optarg) >= 0 && ft_atoi(g_optarg) <= 7)
				logger_init(ft_atoi(g_optarg), PROG_NAME, "sh.log");
			else
			{
				ft_printf("%s: Invalid debug level.\n", PROG_NAME);
				sh_help_exit();
			}
		else if (opt == 'h')
			sh_help_exit();
		else if (opt == 't')
			sh_testing(g_optarg);
		else if (opt == '?')
			sh_help_exit();
	}
}

t_sh_data		*sh_init(t_sh_data *data, int ac, char *const *av)
{
	ft_bzero(data, sizeof(*data));
	sh_options(&data->opts, ac, av);
	sh_init_environ();
	sh_builtins_init();
	if ((data->cwd = getcwd(data->cwd, MAXPATHLEN + 1)))
		if (!(sh_getenv("TERM"))
						|| ft_strequ(sh_getenv("TERM")->value, ""))
			sh_setenv("TERM", "dumb");
	if (!data->cwd)
	{
		ft_printf("minishell: error when initialising main data\n");
		sh_data_free(data);
		return (NULL);
	}
	//raw_terminal_mode();
	return (data);
}

void			sh_deinit(t_sh_data *data)
{
	sh_data_free(data);
	//default_terminal_mode();
}