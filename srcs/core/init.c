/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/19 11:07:52 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/init.h>
#include <tests/test.h>
#include <core/help.h>
#include <unistd/ft_unistd.h>
#include <environ/environ.h>
#include <builtins/builtins_utils.h>

extern char const	*g_optarg;

void sh_testing(const char *arg, char *const *av, char **environ)
{
	if (ft_strequ(arg, "env"))
		sh_testing_env(av, environ);
	if (ft_strequ(arg, "lexer"))
		sh_testing_lexer(av);
	if (ft_strequ(arg, "parser"))
		sh_testing_parser(av);
	if (ft_strequ(arg, "ast"))
		sh_testing_ast(av);

	else
	{
		ft_dprintf(STDERR_FILENO, "Unknown testing arg.\n");
        sh_usage_help_exit();
	}
}

static void sh_options(t_sh_opt *opts, int ac, char *const *av, char **environ)
{
	int opt;

	while ((opt = ft_getopt(ac, av, "hvd:t:")) >= 0)
	{
		if (opt == 'v')
			opts->verbose = 1;
		else if (opt == 'd')
			if (ft_atoi(g_optarg) >= 0 && ft_atoi(g_optarg) <= 7)
				logger_init(ft_atoi(g_optarg), PROGNAME, "sh.log");
			else
			{
				ft_printf("%s: Invalid debug level.\n", PROGNAME);
                sh_usage_help_exit();
			}
		else if (opt == 'h')
            sh_usage_help_exit();
		else if (opt == 't')
			sh_testing(g_optarg, av, environ);
		else if (opt == '?')
            sh_usage_help_exit();
	}
}

t_sh_data		*sh_init(t_sh_data *data, int ac, char *const *av, char **environ)
{
	ft_bzero(data, sizeof(*data));
	sh_options(&data->opts, ac, av, environ);
	sh_init_environ(environ);
	sh_builtins_init();
	sh_history_init(NULL);
	init_signals(signals_handler);
	if ((data->cwd = getcwd(data->cwd, MAXPATHLEN + 1)) == NULL)
	{
		ft_printf("%s: Error when getting current working directory\n", PROGNAME);
		sh_data_free(data);
		exit (1);;
	}
	if (!(sh_getenv("TERM")) || ft_strequ(sh_getenv("TERM")->value, ""))
			sh_setenv("TERM", "dumb");
	if ((tgetent(0, sh_getenv_value("TERM"))) != 1)
	{
		ft_printf("%s: Error on tgetent\n", PROGNAME);
		sh_data_free(data);
		exit (1);
	}
	//raw_terminal_mode();
	return (data);
}

struct termios    *sh_store_tattr(void)
{
	int ttyDevice;
	struct termios termAttributes;

	ttyDevice = STDOUT_FILENO;
	if ( !isatty(ttyDevice) )
		return(1);
	else
		if (tcgetattr(ttyDevice, &termAttributes) != 0)
			perror("tcgetattr error");
}