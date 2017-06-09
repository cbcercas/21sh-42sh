/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:51:56 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/08 18:06:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins_utils.h>

void	get_opt_reset(void)
{
	optarg = NULL;
	optind = 1;
	opterr = 0;
	optopt = 0;
}

void	sh_history_help(char *arg)
{
	ft_printf("bash: history: %s: invalid option\n", arg);
	ft_printf("history: usage: history [-c] [-d offset] [n] or history");
 	ft_printf("-awrn [filename] or history -ps arg [arg...]\n");
}


int sh_history(t_sh_data *data, char **argv)
{
	(void)data;
	int		opt;

	//TODO : reset get_opt
	get_opt_reset();

	opt = getopt(ft_tablen(argv), argv, "cd:arws");//TODO: mettre ft_getopt quand il y'aura un reset
	if (opt == 'c')
		sh_history_builtin_c();
	else if (opt == 'd')
		sh_history_builtin_d(optarg);
	else if(opt == 'a')
		sh_history_builtin_a(argv[optind]);
	else if(opt == 'r')
		sh_history_init(argv[optind]);
	else if(opt == 'w')
		sh_history_builtin_w(argv[optind]);
	else if(opt == 's')
		sh_history_builtin_s(argv, optind);
	else if (opt == -1)
		sh_history_builtin_print(argv[optind]);
	else if (opt == '?')
		sh_history_help(argv[1]);
		//TODO : reset get_opt
		get_opt_reset();
	return (0);
}
