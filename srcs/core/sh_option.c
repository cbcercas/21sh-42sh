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
#include <malloc_test.h>

extern char const	*g_optarg;
extern int			g_optind;

/*
** @brief     Helper to Handle the options passed to the program
**
** @param opts     Contains the options passed by the user
** @param opt      Option given by getopt
** @param av       Contains the arguments
** @param environ  Contains the env
**
** @return    void
*/

static	void	sh_options_loop(int opt, t_sh_opt *opts, char *const *av,
										char **environ)
{
	if (opt == 'v')
		opts->verbose = true;
	else if (opt == 'd')
		if (ft_atoi(g_optarg) >= 0 && ft_atoi(g_optarg) <= 7)
			logger_init((enum e_d_lvl)ft_atoi(g_optarg), PROGNAME, "sh.log");
		else
		{
			ft_dprintf(2, "%s: Invalid debug level.\n", PROGNAME);
			sh_usage_help_exit();
		}
	else if (opt == 'C')
		opts->color = true;
	else if (opt == 'h' || opt == '?')
		sh_usage_help_exit();
	else if (opt == 't')
		sh_testing(g_optarg, &av[g_optind], environ);
	else if (opt == 'l' || !isatty(STDIN_FILENO))
		opts->tcaps = false;
}

/*
** @brief Handles the options passed to the program
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
	int		opt;
	BOOL	ret;

	ret = false;
	opts->tcaps = true;
	opts->color = false;
	ft_getopt_reset();
	while ((opt = ft_getopt(ac, av, "schvd:t:lCM:")) >= 0)
	{
		if (opt == 'c')
			ret = true;
		else if (opt == 's')
			ret = false;
		else if (opt == 'M')
			ft_memalloc_test_init((size_t)ft_atoi(g_optarg));
		else
			sh_options_loop(opt, opts, av, environ);
	}
	if (ret)
		sh_testing_exec(&av[g_optind], environ);
}
