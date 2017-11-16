/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:13:37 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 17:13:39 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/init.h>
#include <libft.h>
#include <tests/sh_tests.h>
#include <core/help.h>

extern char const	*g_optarg;

/*
** @brief     Handles the options passed to the program
**
** @param[in,out] opts     Contains the options passed by the user
** @param[in] ac       Argument count for av
** @param[in] av       Contains the arguments
** @param[in] environ  Contains the env
**
** @return    void
*/

void			sh_options(t_sh_opt *opts, int ac, char *const *av,
						char **environ)
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
		else if (opt == 'l' || !isatty(STDOUT_FILENO))
			opts->tcaps = false;
		else if (opt == 'c')
			sh_testing_exec(av, environ);
	}
}
