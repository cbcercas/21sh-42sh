/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/10 18:15:48 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/init.h>

extern char const	*g_optarg;

/**
 * @brief     Function is called when a test is needed on one module
 *
 * @param[in] arg      Contains the module name to be tested
 * @param[in] av       Contains the parameters needed for the test function
 * @param[in] environ  Contains the env (Used when needed by the testing functions)
 *
 * @return    void
 */

void		sh_testing(const char *arg, char *const *av, char **environ)
{
	if (ft_strequ(arg, "env"))
		sh_testing_env(av, environ);
	else if (ft_strequ(arg, "lexer"))
		sh_testing_lexer(av);
	else if (ft_strequ(arg, "parser"))
		sh_testing_parser(av);
	else if (ft_strequ(arg, "ast"))
		sh_testing_ast(av, environ);
	else if (ft_strequ(arg, "expand"))
		sh_testing_expand(av, environ);
	else if (ft_strequ(arg, "var"))
		testing_local_vars(av, environ);
	else
	{
		ft_dprintf(STDERR_FILENO, "Unknown testing arg.\n");
		sh_usage_help_exit();
	}
}

/**
 * @brief     Handles the options passed to the program
 *
 * @param[in,out] opts     Contains the options passed by the user
 * @param[in] ac       Argument count for av
 * @param[in] av       Contains the arguments
 * @param[in] environ  Contains the env
 *
 * @return    void
 */

static void	sh_options(t_sh_opt *opts, int ac, char *const *av, char **environ)
{
	int opt;

	opts->tcaps = true;
	while ((opt = ft_getopt(ac, av, "chvd:t:l")) >= 0)
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
		else if (opt == 'h' || opt == '?')
			sh_usage_help_exit();
		else if (opt == 't')
			sh_testing(g_optarg, av, environ);
		else if (opt == 'l')
			opts->tcaps = false;
		else if (opt == 'c')
			sh_testing_exec(av, environ);
	}
}

/**
 * @brief     Initializes the program
 *
 * @param[in] data     Contains data such as options and env
 * @param[in] ac       Argument count for av
 * @param[in] av       Contains the arguments
 * @param[in] environ  Contains the env
 *
 * @return    the modified t_sh_data
 */

t_sh_data	*sh_init(t_sh_data *data, int ac, char *const *av, char **environ)
{

	ft_bzero(data, sizeof(*data));
	sh_options(&data->opts, ac, av, environ);
	init_environ(environ);
	init_local_var();
	sh_builtins_init();
	sh_history_init();
	init_signals(signals_handler);
	sh_store_tattr(data);
	if ((data->cwd = getcwd(data->cwd, MAXPATHLEN + 1)) == NULL)
	{
		ft_printf("%s: Error when getting current working directory\n",\
																	PROGNAME);
		sh_deinit(data);
		exit(1);
	}
	if (!(get_var(get_envs(), "TERM")) || ft_strequ(get_var(get_envs(), "TERM")->value, ""))
		set_var(get_envs(), "TERM", "xterm");
	if (get_var_value(get_envs(),"SHLVL"))
		set_var(get_envs(),"SHLVL", ft_itoa(ft_atoi(get_var_value(get_envs(),"SHLVL")) + 1)); //TODO, Atoi secure
	else
		set_var(get_envs(),"SHLVL", ft_strdup("1"));
	if ((tgetent(0, get_var_value(get_envs(),"TERM"))) != 1)
	{
		ft_printf("%s: Error on tgetent\n", PROGNAME);
		sh_deinit(data);
		exit(1);
	}
	log_info("%s initialized correctly. SHLVL is set to %s", PROGNAME,
			 get_var_value(get_envs(),"SHLVL"));
	return (data);
}

/**
 * @brief         Stores the attributes to be restored later
 *
 * @param[in,out] data  Struct that will contain the data
 *
 * @return        void
 */

void		sh_store_tattr(t_sh_data *data)
{
	int				ttydevice;
	struct termios	save_tattr;

	ttydevice = STDOUT_FILENO;
	if (tcgetattr(ttydevice, &save_tattr) != 0)
	{
		ft_printf("%s: tcgetattr error when trying", PROGNAME);
		ft_printf(" to save terminal attributes\n");
		return ;
	}
	else if ((data->tattr = (struct termios*)malloc(sizeof(struct termios))))
		ft_memcpy(data->tattr, &save_tattr, sizeof(struct termios));
	return ;
}
