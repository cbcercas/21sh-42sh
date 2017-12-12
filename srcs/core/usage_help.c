/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 16:12:21 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <automaton/automaton.h>
#include <core/progname.h>

/*
** @brief Prints the help when using a wrong option
*/

void		sh_usage_help(void)
{
	ft_printf("Usage:\t./%s [option] ...\n", PROGNAME);
	ft_printf("Shell options:\n");
	ft_printf("\t-v\t\tVerbose\n");
	ft_printf("\t-d [0-7]\t\tDebug mode (need debug level):\n");
	ft_printf("\t\t\t\t0: no log\n\t\t\t\t1: fatal\n\t\t\t\t2: error\n");
	ft_printf("\t\t\t\t3: warning\n\t\t\t\t4: info\n");
	ft_printf("\t\t\t\t5: debug level 1\n\t\t\t\t6: debug level 2");
	ft_printf("\n\t\t\t\t7: debug level 3\n");
	ft_printf("\t-t\t\ttesting mode:\n");
	ft_printf("\t\t\t\tenv: test env module\n");
	ft_printf("\t\t\t\t\t set VAR=value ... : set variable(s) and display"
																	"env\n");
	ft_printf("\t\t\t\t\t del VAR ... : delete variable(s) and display env\n");
	ft_printf("\t\t\t      lexer: test lexer module\n");
	ft_printf("\t\t\t     parser: test parser module\n");
	ft_printf("\t\t\t     expand: test expand module\n");
	ft_printf("\t-c [string]\t\t If the -c option is present, then commands"
					" are read from string.\n");
	ft_printf("\t-C Allows color in builtins. default in testing is true,"
					" otherwise by default is false\n");
	ft_printf("\t-l\t\tDisables the termcaps capabilities\n");
}

/*
** TODO: Add color in the usage_help
*/

/*
** @brief Prints the usage and exits
*/

void		sh_usage_help_exit(void)
{
	sh_usage_help();
	exit(EXIT_FAILURE);
}
