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

#include <builtins/builtin_history.h>

extern char const	*g_optarg;
extern int			g_optind;

/*
** @brief Displays the help for the history builtin
*/

static void	sh_history_help(void)
{
	ft_printf("history: usage: history [-c] [-d offset] [n] or history");
	ft_printf("-awrn [filename] or history -ps arg [arg...]\n");
}

/*
** @brief Handles the options passed to the history builtin
**
** @param data The shell's data used across the program
** @param args The options in string form
** @param opt The options passed
**
** @return Returns 1 if the options given are wrong, 0 otherwise
*/

static int	sh_history_helper(t_sh_data *data, char **args, int opt)
{
	(void)data;
	if (opt == 'p')
		sh_history_builtin_p(args);
	else if (opt == -1)
		sh_history_builtin_print(args[g_optind]);
	else if (opt == '?')
	{
		sh_history_help();
		return (1);
	}
	return (0);
}

/*
** @brief Main function for the history builtin
**
** @param data The shell's data used across the program
** @param args The arguments passed to history
**
** @return Returns a ret status upon success or failure
*/

int			sh_history(t_sh_data *data, char **args)
{
	int		opt;
	int		ret;

	(void)data;
	ret = 0;
	ft_getopt_reset();
	opt = ft_getopt(((int)ft_tablen(args)), args, "cd:arwsnp");
	if (opt == 'c')
		sh_history_builtin_c();
	else if (opt == 'd')
		sh_history_builtin_d(g_optarg);
	else if (opt == 'a')
		sh_history_builtin_a(args[g_optind]);
	else if (opt == 'n')
		sh_history_builtin_n(args[g_optind]);
	else if (opt == 'r')
		sh_history_builtin_r(args[g_optind]);
	else if (opt == 'w')
		sh_history_builtin_w(args[g_optind]);
	else if (opt == 's')
		sh_history_builtin_s(args, g_optind);
	else
		ret = sh_history_helper(data, args, opt);
	ft_getopt_reset();
	return (ret);
}
