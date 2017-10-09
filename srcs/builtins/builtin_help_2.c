/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:19:22 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:20:36 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/help.h>

/*
**TODO: ADD MORE COLORS
*/

void	sh_help_exit(void)
{
	ft_printf("\texit [n]\nCause the shell to exit with a status of n.\n");
	ft_printf("If n is omitted, the exit status is that of the last command \
executed.\n");
	ft_printf("A trap on EXIT is executed before the shell terminates.\n");
}

void	sh_help_cd(void)
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

void	sh_help_setenv(void)
{
	ft_printf("\tsetenv [name]=[value]\n");
	ft_printf("Sets the environment variable name with value value\n");
	ft_printf("If name already has a value, then it is replaced with the \
new one\n");
}

void	sh_help_unsetenv(void)
{
	ft_printf("\tunsetenv [name]\n");
	ft_printf("Deletes the environment variable name from local env\n");
	ft_printf("If name doesnt exists, nothing happens\n");
	ft_printf("Optional arguments shall be passed to utility.\n");
}

void	sh_help_env(void)
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
	ft_printf("\nThe following operands shall be supported:\n\n");
	ft_printf("\t   name=value\n");
	ft_printf("\t\t  Arguments of the form name= value shall modify the ");
	ft_printf("execution environment, and shall\n");
	ft_printf("\t\t  be placed into the inherited environment before the ");
	ft_printf("utility is invoked.\n\n");
	ft_printf("\t   utility\n");
	ft_printf("\t\t  The name of the utility to be invoked. If the utility");
	ft_printf(" operand names any of the spe-\n");
	ft_printf("\t\t  cial built-in utilities in Special Built-In Utilities,");
	ft_printf(" the results are undefined.\n\n\t   argument\n");
	ft_printf("\t\t  A string to pass as an argument for the invoked \
utility.\n");
}
