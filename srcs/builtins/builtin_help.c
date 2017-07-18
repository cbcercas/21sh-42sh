/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:29:44 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 12:22:12 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/help.h>

void sh_help_default(t_sh_data *data)
{
	(void)data;
	ft_printf("#-- %s Version 42 --#\n", PROGNAME);
	ft_printf("These shell commands are defined internally.  Type `help' to");
	ft_printf(" see this list.\n");
	ft_printf("Type `help name' to find out more about the function `name'.\n");
	ft_printf("\n\nA star (*) next to a name means that the command is disabled.\n");
	ft_printf("\necho [-neE] [arg …]\n");
	ft_printf("help [pattern]\n");
	ft_printf("exit [n]\n");
	ft_printf("cd [-L|-P] [directory]\n");
	ft_printf("setenv [name]=[value]\n");
	ft_printf("unsetenv [name]\n");
	ft_printf("env [-i][name=value]...\t[utility [argument...]]\n");
	ft_printf("bonus [Displays the bonuses for this project]\n");
}

void sh_help_echo(void)
{
	ft_printf("\techo [-neE] [arg …]\n");
	ft_printf("Output the args, separated by spaces, terminated with a ");
	ft_printf("newline.\nThe return status is 0 unless a write error ");
	ft_printf("occurs.\nIf -n is specified, the trailing newline is ");
	ft_printf("suppressed.\nIf the -e option is given, interpretation of");
	ft_printf(" the following backslash-escaped characters is enabled.\n");
	ft_printf("echo does not interpret -- to mean the end of options.\n");
	ft_printf("\necho interprets the following escape sequences: \n");
	ft_printf("\n\\a\n\n\talert (bell) ");
	ft_printf("\n\\n\n\n\tnew line ");
	ft_printf("\n\\r\n\n\tcarriage return ");
	ft_printf("\n\\b\n\n\tbackspace ");
	ft_printf("\n\\f\n\n\tform feed ");
	ft_printf("\n\\t\n\n\thorizontal tab ");
	ft_printf("\n\\v\n\n\tvertical tab ");
	ft_printf("\n\\\\\n\n\tbackslash\n");

} //TODO: ADD COLORS

void sh_help_help(void)
{
	ft_printf("\thelp [pattern]\nDisplay helpful information about builtin commands.\n");
	ft_printf("If pattern is specified, help gives detailed help on command matching");
	ft_printf(" pattern,\notherwise a list of the builtins is printed.\n");
}

void sh_help_exit(void)
{
	ft_printf("\texit [n]\nCause the shell to exit with a status of n.\n");
	ft_printf("If n is omitted, the exit status is that of the last command executed.\n");
	ft_printf("A trap on EXIT is executed before the shell terminates.\n");
}

void sh_help_cd(void)
{
	ft_printf("\tcd [-L|-P] [directory]\n");
	ft_printf("Change the current working directory to directory.\n");
	ft_printf("If directory is not supplied, the value of the HOME shell ");
	ft_printf("variable is used.\n");
	ft_printf("Any additional arguments following directory are ignored.\n");
	ft_printf("The -P option means to not follow symbolic links: symbolic");
	ft_printf(" links are resolved while cd is traversing directory and");
	ft_printf(" before processing an instance of ‘..’ in directory.\n");
	ft_printf("By default, or when the -L option is supplied, symbolic links");
	ft_printf(" in directory are resolved after cd processes an instance of");
	ft_printf(" ‘..’ in directory.\n");
	ft_printf("If directory is ‘-’, it is converted to $OLDPWD before the");
	ft_printf("directory change is attempted.\n");
	ft_printf("The return status is zero if the directory is successfully");
	ft_printf("changed, non-zero otherwise.\n");
}

void sh_help_setenv(void)
{
	ft_printf("\tsetenv [name]=[value]\n");
	ft_printf("Sets the environment variable name with value value\n");
	ft_printf("If name already has a value, then it is replaced with the new one\n");
}

void sh_help_unsetenv(void)
{
	ft_printf("\tunsetenv [name]\n");
	ft_printf("Deletes the environment variable name from local env\n");
	ft_printf("If name doesnt exists, nothing happens\n");
	ft_printf("Optional arguments shall be passed to utility.\n");
}

void sh_help_env(void)
{
	ft_printf("\tenv [-i][name=value]...\t[utility [argument...]]\n");
	ft_printf("Obtains the current environment, modify it according to its ");
	ft_printf("arguments, \nthen invoke the utility operand with the");
	ft_printf(" modified environment.\n");
	ft_printf("If no utility operand is specified, the resulting environment");
	ft_printf(" shall \nbe written to the standard output, with one ");
	ft_printf("name=value pair per line.\n");
	ft_printf("\n-i \tInvoke utility with exactly the environment specified");
	ft_printf(" by the arguments;\n");
	ft_printf("\tthe inherited environment shall be ignored completely.\n");
	ft_printf("\nThe following operands shall be supported:\n");
	ft_printf("\n");
	ft_printf("\t   name=value\n");
	ft_printf("\t\t  Arguments of the form name= value shall modify the ");
	ft_printf("execution environment, and shall\n");
	ft_printf("\t\t  be placed into the inherited environment before the ");
	ft_printf("utility is invoked.\n");
	ft_printf("\n");
	ft_printf("\t   utility\n");
	ft_printf("\t\t  The name of the utility to be invoked. If the utility");
	ft_printf(" operand names any of the spe-\n");
	ft_printf("\t\t  cial built-in utilities in Special Built-In Utilities,");
	ft_printf(" the results are undefined.\n");
	ft_printf("\n");
	ft_printf("\t   argument\n");
	ft_printf("\t\t  A string to pass as an argument for the invoked");
	ft_printf(" utility.\n");
}

void sh_help_bonus(void)
{
	ft_printf("\tbonus - Bonuses for %s\n", PROGNAME);
	ft_printf("\t\tBuiltin help\n");
	ft_printf("\t\tSGG | ShellGrammarGenerator\n");
}

int sh_builtin_help(t_sh_data *data, char **args)
{
	(void) data;
	if (args[1] == NULL)
	{
		sh_help_default(data);
		return (0);
	}
	if (ft_strequ(args[1], "echo"))
	{
		sh_help_echo();
		return (0);
	}
	else if (ft_strequ(args[1], "help"))
	{
		sh_help_help();
		return (0);
	}
	else if (ft_strequ(args[1], "exit"))
	{
		sh_help_exit();
		return (0);
	}
	else if (ft_strequ(args[1], "cd"))
	{
		sh_help_cd();
		return (0);
	}
	else if (ft_strequ(args[1], "setenv"))
	{
		sh_help_setenv();
		return (0);
	}
	else if (ft_strequ(args[1], "unsetenv"))
	{
		sh_help_unsetenv();
		return (0);
	}
	else if (ft_strequ(args[1], "env"))
	{
		sh_help_env();
		return (0);
	}
	else if (ft_strequ(args[1], "bonus"))
	{
		sh_help_bonus();
		return (0);
	}
	return (0);
}
