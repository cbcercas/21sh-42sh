/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:51:56 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 19:13:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>
#include <core/data.h>
#include <builtins/builtin_history.h>
#include <unistd/ft_unistd.h>

extern char const	*g_optarg;
extern int			g_optind;

void		sh_history_help(char *arg)
{
	(void)arg;
	ft_printf("history: usage: history [-c] [-d offset] [n] or history");
	ft_printf("-awrn [filename] or history -ps arg [arg...]\n");
}

static int	sh_history_helper(t_sh_data *data, char **argv, int opt)
{
	(void)data;
	if (opt == 'p')
		sh_history_builtin_p(argv);
	else if (opt == -1)
		sh_history_builtin_print(argv[g_optind]);
	else if (opt == '?')
	{
		sh_history_help(argv[1]);
		return (1);
	}
	return (0);
}

int			sh_history(t_sh_data *data, char **argv)
{
	int		opt;
	int		ret;

	(void)data;
	ret = 0;
	ft_getopt_reset();
	opt = ft_getopt(ft_tablen(argv), argv, "cd:arwsnp");
	if (opt == 'c')
		sh_history_builtin_c();
	else if (opt == 'd')
		sh_history_builtin_d(g_optarg);
	else if (opt == 'a')
		sh_history_builtin_a(argv[g_optind]);
	else if (opt == 'n')
		sh_history_builtin_n(argv[g_optind]);
	else if (opt == 'r')
		sh_history_builtin_r(argv[g_optind]);
	else if (opt == 'w')
		sh_history_builtin_w(argv[g_optind]);
	else if (opt == 's')
		sh_history_builtin_s(argv, g_optind);
	else
		ret = sh_history_helper(data, argv, opt);
	ft_getopt_reset();
	return (ret);
}
