/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:51:56 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/19 14:43:21 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins_utils.h>

void		sh_history_help(char *arg)
{
	(void)arg;
	ft_printf("history: usage: history [-c] [-d offset] [n] or history");
	ft_printf("-awrn [filename] or history -ps arg [arg...]\n");
}

static void	sh_history_helper(t_sh_data *data, char **argv, int opt)
{
	(void)data;
	if (opt == 'p')
		sh_history_builtin_p(argv);
	else if (opt == -1)
		sh_history_builtin_print(argv[optind]);
	else if (opt == '?')
		sh_history_help(argv[1]);
}

int			sh_history(t_sh_data *data, char **argv)
{
	int		opt;

	(void)data;
	ft_getopt_reset();
	opt = ft_getopt(ft_tablen(argv), argv, "cd:arwsnp");
	if (opt == 'c')
		sh_history_builtin_c();
	else if (opt == 'd')
		sh_history_builtin_d(optarg);
	else if (opt == 'a')
		sh_history_builtin_a(argv[optind]);
	else if (opt == 'n')
		sh_history_builtin_n(argv[optind]);
	else if (opt == 'r')
		sh_history_builtin_r(argv[optind]);
	else if (opt == 'w')
		sh_history_builtin_w(argv[optind]);
	else if (opt == 's')
		sh_history_builtin_s(argv, optind);
	else
		sh_history_helper(data, argv, opt);
	ft_getopt_reset();
	return (0);
}
