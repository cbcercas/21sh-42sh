/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:29:44 by jlasne            #+#    #+#             */
/*   Updated: 2017/06/19 14:30:43 by jlasne           ###   ########.fr       */
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
	return (0);
}