/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:07 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 14:46:46 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_exit.h>
#include <core/color.h>

/*
** @brief Exits the program properly with a given status
**
** @param data The shell's data
**
** @param arg The status
*/

void	sh_print_fed3(void)
{
	ft_printf("          ▐████   █████                                  █████`"
					"  █████\n");
	ft_printf("           ████▓   ▀████▄                              ▄████▀  "
					" ▄████`\n");
	ft_printf("            ████▓   ╙████▓                            ▓████▀   "
					"▄████▀\n");
	ft_printf("             █████    █████                         ,█████    "
					"▓████▀\n");
	ft_printf("              █████▄   ▀████▄                      ▄████▀   "
					"▄█████,\n");
	ft_printf("               ╙█████▄  ╙████▌                    ▓████▀  "
					"▄█████▀\n");
	ft_printf("                 ▀█████▓▄ █████                 ,████▀ "
					",▓█████▀¬\n");
	ft_printf("                   ╙█████▌ ▀████▄              4▀▀ "
					",▄▓██████▀\n");
	ft_printf("                      ▀████ ╙████▌           ,▄▄▓████████▀─\n");
	ft_printf("                         └▀█▄ █████ ^████████████████▀▀\n");
	ft_printf("                               ▀████▄ ████████▀▀▀▀─\n");
	ft_printf("                                ╙████▌    ▄▄▄▓▓▀\n");
	ft_printf("                                  █████  ▓████▀\n");
	ft_printf("                                   ▀█████████\n");
	ft_printf("                                    ╙██████▀\n");
	ft_printf("                                      ████▀\n");
	ft_printf("                                       ▀█\n");
}

void	sh_print_fed2(void)
{
	ft_printf("          ████¬ ▄                                              "
					",█████\n");
	ft_printf("         ▐████ ▐█▓                                            "
					"▄████▀ ▄▌\n");
	ft_printf("         ▐████ ╟███                                          "
					"▓████` ██▌\n");
	ft_printf("         j████ ▐████▄                                      "
					"╓████▀ ▄███▌\n");
	ft_printf("          ████▌ ╙████▓                                    "
					"▄████▀ ╒████~\n");
}

void	sh_print_fed1(void)
{
	ft_printf("%s", C_BLUE);
	ft_printf("                                  ,,▄▄▄▄▄▄▄▄,,\n");
	ft_printf("                           ,▄▄▓██████████████████▓▄▄,\n");
	ft_printf("                       ,▄▓█████████▀▀▀▀▀▀▀▀▀▀██████████▄,\n");
	ft_printf("                    .Æ███████▀▀¬                 ^▀▀██████▓,\n");
	ft_printf(" ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ ▀██████▄ "
					"*▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n");
	ft_printf("  ████████████████████████████████████████████████████▓▄ "
					"▀█████▄ "
					"▀████████████`\n");
	ft_printf("   ▀█████▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀  "
					"╙█████µ^▀▀▀▀█████▀\n");
	ft_printf("    ╙█████   ▄█████                                          "
					"▀████▌   ▄████▀\n");
	ft_printf("      █████ ▄████▀                                             "
					"████  ▓████`\n");
	ft_printf("       ▀██ ▐████▀                                               "
					"██ ,████▀\n");
	ft_printf("        ╙▀]████▌                                                "
					"  ▄████▀\n");
	ft_printf("          █████                                                 "
					" ▓████¬\n");
	sh_print_fed2();
	sh_print_fed3();
	ft_printf("%s", C_NONE);
	ft_printf("\t\t\t\tVive la Federation !\n");
}

void	sh_exit(t_sh_data *data, char **arg)
{
	int		status;

	status = 0;
	sh_history_save();
	if (data)
		sh_deinit(data);
	default_terminal_mode();
	ft_printf("exit\n");
	if (arg && arg[1] && ft_isdigit(arg[1][0]))
		status = ft_atoi(arg[1]);
	kill_childs(SIGTERM);
	if (data && data->opts.color && get_windows(0) &&
			get_windows(0)->ts.ws_col >= 80)
		sh_print_fed1();
	exit(status);
}

/*
** @brief Calls sh_exit()
**
** @param data The shell data used across the program
**
** @param arg The args passed to exit (The exit status)
*/

int		builtin_exit(t_sh_data *data, char **arg)
{
	sh_exit(data, arg);
	return (EXIT_FAILURE);
}
