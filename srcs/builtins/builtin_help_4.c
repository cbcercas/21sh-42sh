/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:19:22 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:20:36 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_help.h>

/*
** @brief Displays the help for the env builtin (helper)
*/

void	sh_help_env_helper(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("\nThe following operands shall be supported:\n\n");
	ft_printf("\t   %sname%s=%svalue%s\n", (col) ? C_CYAN : "", C_NONE,
			(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\t\t  Arguments of the form %sname%s=%svalue%s shall modify the",
			(col) ? C_CYAN : "", C_NONE, (col) ? C_MAGENTA : "", C_NONE);
	ft_printf(" execution environment, and shall\n");
	ft_printf("\t\t  be placed into the inherited environment before the ");
	ft_printf("%sutility%s is invoked.\n", (col) ? C_BROWN : "", C_NONE);
	ft_printf("\t   %sutility%s\n", (col) ? C_BROWN : "", C_NONE);
	ft_printf("\t\t  The name of the utility to be invoked. If the utility");
	ft_printf(" operand names any of the spe-\n");
	ft_printf("\t\t  cial built-in utilities in Special Built-In Utilities,");
	ft_printf(" the results are undefined.\n\t   %sargument%s\n",
			(col) ? C_GREEN : "", C_NONE);
	ft_printf("\t\t  A string to pass as an argument for the invoked "
					"%sutility%s.\n", (col) ? C_BROWN : "", C_NONE);
}

/*
** @brief Displays the help for the env builtin
*/

void	sh_help_env(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%senv%s [%s-i%s][%sname%s=%svalue%s]...\t[utility "
					"[%sargument%s...]]\n", (col) ? CL_RED : "", C_NONE,
			(col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE,
			(col) ? C_MAGENTA : "", C_NONE, (col) ? C_GREEN : "", C_NONE);
	ft_printf("\tObtains the current environment, modify it according to its ");
	ft_printf("arguments, then invoke the utility operand with the");
	ft_printf(" modified environment.\n");
	ft_printf("If no utility operand is specified, the resulting environment");
	ft_printf(" shall be written to the standard output, with one ");
	ft_printf("%sname%s=%svalue%s pair per line.\n", (col) ? C_CYAN : "",
			C_NONE, (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\n%s-i%s \tInvoke utility with exactly the environment "
					"specified", (col) ? C_CYAN : "", C_NONE);
	ft_printf(" by the arguments;\n");
	ft_printf("\tthe inherited environment shall be ignored completely.\n");
	sh_help_env_helper();
}

void	sh_help_bonus_helper(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("\t%s*Testing mode (-t)\n", (col) ? C_YELLOW : "");
	ft_printf("\t%s*-c option to execute a command\n", (col) ? C_YELLOW : "");
	ft_printf("\t%s*-h option for help!!\n", (col) ? C_YELLOW : "");
	ft_printf("\t%s*-v for Verbose mode\n", (col) ? C_YELLOW : "");
	ft_printf("\t%s*Builtin help\n", (col) ? C_GREEN : "");
	ft_printf("\t%s*MANY COLORS(Make, Prompt, env, help, export, verb, hist) "
					"with -C\n", (col) ? CL_RED : "");
}

/*
** @brief Displays help for bonuses
*/

int		sh_help_bonus(t_sh_data *data, char **args)
{
	BOOL col;

	(void)data;
	(void)args;
	col = get_data(NULL)->opts.color;
	ft_printf("%s%sBONUS - Bonuses for %s%s\n", (col) ? C_MAGENTA : "",
			(col) ? C_UNDER : "", PROGNAME, C_NONE);
	ft_printf("\t%s%s*Dynamic Prompt 🚀%s\n", (col) ? C_BOLD : "",
			(col) ? C_GREEN : "", C_NONE);
	ft_printf("\t\t%s%s-With Super Interactive Smiley (^_^)%s\n",
			(col) ? C_BOLD : "", (col) ? C_GREEN : "", C_NONE);
	ft_printf("\t\t%s%s-With dynamic autocompletion%s\n", (col) ? C_BOLD : "",
			(col) ? C_GREEN : "", C_NONE);
	ft_printf("\t%s*Automated tests suite with Bats Frameworks\n",
			(col) ? CL_BLUE : "");
	ft_printf("\t%s*Multi-ligne editing, even in history\n",
			(col) ? C_CYAN : "");
	ft_printf("\t%s*History backup\n", (col) ? C_CYAN : "");
	ft_printf("\t%s*History autocompletion\n", (col) ? C_CYAN : "");
	ft_printf("\t%s*History search with ctrl-R\n", (col) ? C_CYAN : "");
	ft_printf("\t%s*%s Debug log and with dbg lvl (-d)\n",
			(col) ? C_YELLOW : "", PROGNAME);
	sh_help_bonus_helper();
	return (0);
}

/*
** @brief Displays the help for the history builtin
*/

void	sh_help_history(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%shistory%s [%sn%s] [%scdanrwps%s]\n", (col) ? CL_RED : "",
		C_NONE, (col) ? C_MAGENTA : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\thistory\n");
	ft_printf("\thistory [%sn%s]\n", (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\thistory %s-c%s\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\thistory %s-d%s %soffset%s\n", (col) ? C_CYAN : "", C_NONE,
			(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\thistory [%s-anrw%s] [%sfilename%s]\n", (col) ? C_CYAN : "",
			C_NONE, (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\thistory %s-ps%s %sarg%s\n\n", (col) ? C_CYAN : "", C_NONE,
			(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("With no options, display the history list with line numbers.\n");
	ft_printf("\tOptions, if supplied, have the following meanings:\n");
	ft_printf("%s-c%s\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tClear the history list. This may be combined with the other"
					"options to replace the history list completely.\n");
	ft_printf("%s-d%s offset\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tDelete the history entry at position offset. Offset should "
				"be specified as it appears when the history is displayed.\n");
	ft_printf("%s-a%s\n", (col) ? C_CYAN : "", C_NONE);
	sh_help_history_helper();
}
