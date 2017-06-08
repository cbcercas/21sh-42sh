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

void	sh_history_builtin_c()
{
	t_array	*e;

	ft_printf("clear history\n");
	sh_history_destroy();
	e = sh_history_get();
	if ((e = array_create(sizeof(t_hist))) == NULL)
	{
		log_fatal("Environ: can't initialise history array");
		ft_dprintf(STDERR_FILENO, "Environ: can't initialise hsitory");
		exit(1);
	}
}

int sh_history(t_sh_data *data, char **argv)
{
	(void)data;
	int		opt;

	//TODO : reset get_opt
	get_opt_reset();

	opt = getopt(ft_tablen(argv), argv, "cd:a");//TODO: mettre ft_getopt quand il y'aura un reset
	if (opt == 'c')
		sh_history_builtin_c();
	else if (opt == 'd')
		;//history_bultin_d(atoi(optarg));
	else if(opt == 'a')
		sh_history_builtin_a(argv[optind]);
	else if (opt == -1)
	 sh_history_print(argv[optind]);

		//TODO : reset get_opt
		get_opt_reset();
	return (0);
}
