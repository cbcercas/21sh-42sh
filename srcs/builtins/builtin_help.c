/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:29:44 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:20:59 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_help.h>

/*
** @brief Displays the other part of the default help
*/

void	sh_help_default2(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("\t%secho%s [%s-neE%s] [arg …]\n", (col) ? CL_RED : "", C_NONE,
												(col) ? C_CYAN : "", C_NONE);
	ft_printf("\t%shelp%s [pattern]\n", (col) ? CL_RED : "", C_NONE);
	ft_printf("\t%sexit%s [n]\n", (col) ? CL_RED : "", C_NONE);
	ft_printf("\t%shistory%s [n] [cdanrwps]\n", (col) ? CL_RED : "", C_NONE,
												(col) ? C_CYAN : "", C_NONE);
	ft_printf("\t%scd%s [%s-L%s|%s-P%s] [directory]\n", (col) ? CL_RED : "",
			C_NONE, (col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\t%schdir%s [%s-L%s|%s-P%s] [directory]\n", (col) ? CL_RED : "",
			C_NONE, (col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\t%spwd%s [%s-L%s|%s-P%s] [directory]\n", (col) ? CL_RED : "",
			C_NONE, (col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\t%ssetenv%s [name]=[value]\n", (col) ? CL_RED : "", C_NONE);
	ft_printf("\t%sunsetenv%s [name]\n", (col) ? CL_RED : "", C_NONE);
	ft_printf("\t%senv%s [%s-i%s][name=value]...\t[utility [argument...]]\n",
					(col) ? CL_RED : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\t%sbonus%s (Displays the bonuses for this project)\n",
												(col) ? CL_RED : "", C_NONE);
	ft_printf("\t%sexport%s [%s-n%s] [name[=value] ...] or export %s-p%s\n",
					(col) ? CL_RED : "", C_NONE, (col) ? C_CYAN : "", C_NONE,
												(col) ? C_CYAN : "", C_NONE);
}

/*
** @brief The function display default help first part
*/

void	sh_help_default(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("\n%s#-- %s Help --#\n%s%s", (col) ? CL_BLUE : "", PROGNAME,
																		C_NONE);
	ft_printf("%sThese shell commands are defined internally. Type `%shelp%s' "
				"to see this list.\n", C_NONE, (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("Type `%shelp name%s' to find out more about the function "
								"`%sname%s'.\n", (col) ? C_MAGENTA : "", C_NONE,
												(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\n%sA star%s (*) next to a name means that the command is "
								"disabled.\n\n", (col) ? C_GREEN : "", C_NONE);
	sh_help_default2();
}

/*
** @brief Displays the help for help (Helpcesption)
*/

void	sh_help_help(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%shelp%s [%spattern%s]\n", (col) ? CL_RED : "", C_NONE,
												(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\tDisplay helpful information about builtin commands.\n");
	ft_printf("If %spattern%s is specified, help gives detailed help "
	"on command matching %spattern%s.\n", (col) ? C_MAGENTA : "", C_NONE,
												(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("Otherwise, A list of the builtins is printed.\n");
}

/*
** @brief Displays the help for echo
*/

void	sh_help_echo(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%secho%s [%s-neE%s] [%sarg%s …]\n", (col) ? C_RED : "", C_NONE,
				(col) ? C_CYAN : "", C_NONE, (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\tOutput the args, separated by spaces, terminated with "
																"a newline.\n");
	ft_printf("If %s-n%s is specified, the trailing newline is ",
												(col) ? C_CYAN : "", C_NONE);
	ft_printf("suppressed.\nIf the %s-e%s option is given, interpretation of",
												(col) ? C_CYAN : "", C_NONE);
	ft_printf(" the following backslash-escaped characters is enabled.\n");
	ft_printf("\necho interprets the following escape sequences:\n");
	ft_printf("\t%s\\a%s\talert (bell)\n", (col) ? C_RED : "", C_NONE);
	ft_printf("\t%s\\n%s\tnew line\n", (col) ? C_RED : "", C_NONE);
	ft_printf("\t%s\\r%s\tcarriage return\n", (col) ? C_RED : "", C_NONE);
	ft_printf("\t%s\\b%s\tbackspace\n", (col) ? C_RED : "", C_NONE);
	ft_printf("\t%s\\f%s\tform feed\n", (col) ? C_RED : "", C_NONE);
	ft_printf("\t%s\\t%s\thorizontal tab\n", (col) ? C_RED : "", C_NONE);
	ft_printf("\t%s\\v%s\tvertical tab\n", (col) ? C_RED : "", C_NONE);
	ft_printf("\t%s\\\\%s\tbackslash\n\n", (col) ? C_RED : "", C_NONE);
	ft_printf("echo does not interpret -- to mean the end of options.\n");
	ft_printf("The return status is %s0%s unless a write error occurs.\n",
												(col) ? C_GREEN : "", C_NONE);
}

/*
** @brief The function called when help is executed
**
** @param data The shell data used throughout the program
** @param args The args passed to help
**
** @return Returns the ret value of help based on success or not of the
** operation
*/

int		sh_builtin_help(t_sh_data *data, char **args)
{
	(void)data;
	if (args[1] == NULL)
		sh_help_default();
	else if (ft_strequ(args[1], "echo"))
		sh_help_echo();
	else if (ft_strequ(args[1], "help"))
		sh_help_help();
	else if (ft_strequ(args[1], "exit"))
		sh_help_exit();
	else if (ft_strequ(args[1], "cd"))
		sh_help_cd();
	else if (ft_strequ(args[1], "setenv"))
		sh_help_setenv();
	else if (ft_strequ(args[1], "unsetenv"))
		sh_help_unsetenv();
	else if (ft_strequ(args[1], "env"))
		sh_help_env();
	else if (ft_strequ(args[1], "pwd"))
		sh_help_pwd();
	else
		return (sh_builtin_help_helper(args));
	return (0);
}
