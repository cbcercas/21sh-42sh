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
#include <core/color.h>
#include <core/data.h>

/*
** @brief Prints the help when using a wrong option
*/

void		sh_usage_help(void)
{
	ft_printf("Usage:\t./%s [%soption%s] ...\n", PROGNAME, C_MAGENTA, C_NONE);
	ft_printf("\tShell options:\n\t%s-v%s\n\t\tVerbose\n", C_CYAN, C_NONE);
	ft_printf("\t%s-d%s [%s0%s-%s7%s]\n\t\tDebug mode (Requires debug level)"
					":\n", C_CYAN, C_NONE, C_GREEN, C_NONE, C_GREEN, C_NONE);
	ft_printf("\t\t\t\t%s0%s: no log\n\t\t\t\t%s1%s: fatal\n\t\t\t\t%s2%s: "
				"error\n", C_GREEN, C_NONE, C_GREEN, C_NONE, C_GREEN, C_NONE);
	ft_printf("\t\t\t\t%s3%s: warning\n\t\t\t\t%s4%s: info\n", C_GREEN,
			C_NONE, C_GREEN, C_NONE);
	ft_printf("\t\t\t\t%s5%s: debug level 1\n\t\t\t\t%s6%s: debug level 2",
			C_GREEN, C_NONE, C_GREEN, C_NONE);
	ft_printf("\n\t\t\t\t%s7%s: debug level 3\n", C_GREEN, C_NONE);
	ft_printf("\t%s-t%s\n\t\ttesting mode:\n", C_CYAN, C_NONE);
	ft_printf("\t\t\t%senv%s: test env module\n", C_MAGENTA, C_NONE);
	ft_printf("\t\t\t\t%sset%s VAR=value ... : set variable(s) and display"
												"env\n", C_MAGENTA, C_NONE);
	ft_printf("\t\t\t\t%sdel%s VAR ... : delete variable(s) and display env\n",
														C_MAGENTA, C_NONE);
	ft_printf("\t\t\t%slexer%s: test lexer module\n", C_MAGENTA, C_NONE);
	ft_printf("\t\t\t%sparser%s: test parser module\n", C_MAGENTA, C_NONE);
	ft_printf("\t\t\t%sexpand%s: test expand module\n", C_MAGENTA, C_NONE);
	ft_printf("\t%s-c%s [%sstring%s]\n\t\tIf the -c option is present, then "
		"commands are read from string.\n", C_CYAN, C_NONE, C_MAGENTA, C_NONE);
	ft_printf("\t%s-C%s\n\t\tAllows color in builtins. default in testing is "
					"true, otherwise by default is false\n", C_CYAN, C_NONE);
	ft_printf("\t%s-l%s\n\t\tDisables the termcaps\n", C_CYAN, C_NONE);
}

/*
** @brief Prints the usage and exits
*/

void		sh_usage_help_exit(void)
{
	sh_usage_help();
	exit(EXIT_FAILURE);
}
