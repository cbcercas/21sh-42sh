/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/30 14:28:21 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/help.h>

void sh_usage_help(void)
{
	ft_printf("Usage:\t./%s [option] ...\n", PROGNAME);
	ft_printf("Shell options:\n");
	ft_printf("\t-v\t\tverbose\n");
	ft_printf("\t-d [0-7]\tdebug mode (need debug level):\n");
	ft_printf("\t\t\t\t0: no log\n\t\t\t\t1: fatal\n\t\t\t\t2: error\n");
	ft_printf("\t\t\t\t3: warning\n\t\t\t\t4: info\n");
	ft_printf("\t\t\t\t5: debug level 1\n\t\t\t\t6: debug level 2");
	ft_printf("\n\t\t\t\t7: debug level 3\n");
	ft_printf("\t-t\t\ttesting mode:\n");
	ft_printf("\t\t\t\tenv: test env module\n");
	ft_printf("\t\t\t\t\t set VAR=value ... : set variable(s) and display env\n");
	ft_printf("\t\t\t\t\t del VAR ... : delete variable(s) and display env\n");
	ft_printf("\t\t\t      lexer: test lexer module\n");
	ft_printf("\t\t\t     parser: test lexer module\n");
}

void sh_usage_help_exit(void)
{
	sh_usage_help();
	exit (1);
}
