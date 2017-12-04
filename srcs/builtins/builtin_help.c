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
** @brief The function display default help
** @param data The shell data used throughout the program
**
** @return Returns the ret value of echo
*/

void	sh_help_default(t_sh_data *data)
{
	(void)data;
	ft_printf("\n%s#-- %s Version 42 --#\n%s", B_BLUE, PROGNAME, C_NONE);
	ft_printf("These shell commands are defined internally.  Type `help' to");
	ft_printf(" see this list.\n");
	ft_printf("Type `help name' to find out more about the function `name'.\n");
	ft_printf("\n\n%sA star%s (*) next to a name means that the command is \
disabled.\n", C_GREEN, C_NONE);
	ft_printf("\n%secho%s [%s-neE%s] [arg …]\n", CL_RED, C_NONE,
			C_CYAN, C_NONE);
	ft_printf("%shelp%s [pattern]\n", CL_RED, C_NONE);
	ft_printf("%sexit%s [n]\n", CL_RED, C_NONE);
	ft_printf("%shistory%s [n] [cdanrwps]\n", CL_RED, C_NONE, C_CYAN, C_NONE);
	ft_printf("%scd%s [%s-L|-P%s] [directory]\n", CL_RED, C_NONE, C_CYAN,
			C_NONE);
	ft_printf("%schdir%s [%s-L|-P%s] [directory]\n", CL_RED, C_NONE, C_CYAN,
			C_NONE);
	ft_printf("%spwd%s [%s-L|-P%s] [directory]\n", CL_RED, C_NONE, C_CYAN,
			C_NONE);
	ft_printf("%ssetenv%s [name]=[value]\n", CL_RED, C_NONE);
	ft_printf("%sunsetenv%s [name]\n", CL_RED, C_NONE);
	ft_printf("%senv%s [%s-i%s][name=value]...\t[utility [argument...]]\n",
			CL_RED, C_NONE, C_CYAN, C_NONE);
	ft_printf("%sbonus%s [Displays the bonuses for this project]\n", CL_RED,\
																		C_NONE);
}

/*
** @brief The function display help of help (Inception help!!)
*/

void	sh_help_help(void)
{
	ft_printf("%shelp%s [pattern]\n", CL_RED, C_NONE);
	ft_printf("\tDisplay helpful information about builtin");
	ft_printf(" commands.\n");
	ft_printf("If pattern is specified, help gives detailed help on command");
	ft_printf(" matching");
	ft_printf(" pattern,\notherwise a list of the builtins is printed.\n");
}

/*
** @brief The function display help of echo
*/

void	sh_help_echo(void)
{
	ft_printf("\t%secho%s [-neE] [arg …]\n", C_RED, C_NONE);
	ft_printf("Output the args, separated by spaces, terminated with a ");
	ft_printf("newline.\nThe return status is 0 unless a write error ");
	ft_printf("occurs.\nIf %s-n%s is specified, the trailing newline is ",
																C_CYAN, C_NONE);
	ft_printf("suppressed.\nIf the %s-e%s option is given, interpretation of",
																C_CYAN, C_NONE);
	ft_printf(" the following backslash-escaped characters is enabled.\n");
	ft_printf("echo does not interpret -- to mean the end of options.\n");
	ft_printf("\necho interprets the following escape sequences: \n");
	ft_printf("\n%s\\a%s\talert (bell)\n", C_RED, C_NONE);
	ft_printf("%s\\n%s\tnew line\n", C_RED, C_NONE);
	ft_printf("%s\\r%s\tcarriage return\n", C_RED, C_NONE);
	ft_printf("%s\\b%s\tbackspace\n", C_RED, C_NONE);
	ft_printf("%s\\f%s\tform feed\n", C_RED, C_NONE);
	ft_printf("%s\\t%s\thorizontal tab\n", C_RED, C_NONE);
	ft_printf("%s\\v%s\tvertical tab\n", C_RED, C_NONE);
	ft_printf("%s\\\\%s\tbackslash\n", C_RED, C_NONE);
}

/*
** @brief The function display bonus
*/

void	sh_help_bonus(void)
{
	ft_printf("\n\t%sBONUS - Bonuses for %s%s\n", C_UNDER, PROGNAME, C_NONE);
	ft_printf("\t\t%s%s*Dynamique Prompt ! 🚀%s\n", C_BOLD, C_GREEN, C_NONE);
	ft_printf("\t\t\t%s%s-With Super Smiley ! (^_^)%s\n",
			C_BOLD, C_GREEN, C_NONE);
	ft_printf("\t\t%s*Tests with Bats Frameworks!\n", CL_BLUE);
	ft_printf("\t\t%s*multi lignes even in history!!\n", C_CYAN);
	ft_printf("\t\t%s*history backup!!\n", C_CYAN);
	ft_printf("\t\t%s*history autocomplete!!\n", C_CYAN);
	ft_printf("\t\t%s*ctrl-R!!\n", C_CYAN);
	ft_printf("\t\t%s*21sh mod debug with log and lvl (-d)!!\n", C_YELLOW);
	ft_printf("\t\t%s*mode testing (-t)!!\n", C_YELLOW);
	ft_printf("\t\t%s*the option -c!!\n", C_YELLOW);
	ft_printf("\t\t%s*-h!!\n", C_YELLOW);
	ft_printf("\t\t%s*-v mode verbose!!\n", C_YELLOW);
	ft_printf("\t\t%s*builtins chdir ;) \n", C_GREEN);
	ft_printf("\t\t%s*Builtin help\n", C_GREEN);
	ft_printf("\t\t%s*MANY COLORS(Make, Prompt, env, help, export, verb, hist)"
					"\n", CL_RED);
}

/*
** @brief The function called when help is executed
** @param data The shell data used throughout the program
** @param argv The args passed to help
**
** @return Returns the ret value of help
*/

int		sh_builtin_help(t_sh_data *data, char **args)
{
	if (args[1] == NULL)
		sh_help_default(data);
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

/*
**TODO: ADD MORE COLORS
*/
