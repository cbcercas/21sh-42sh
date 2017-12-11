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

#include <builtins/builtin_help.h>

/*
** @brief The function display help exit
*/

void	sh_help_exit(void)
{
	ft_printf("%sexit%s [%sn%s]\n", CL_RED, C_NONE, C_MAGENTA, C_NONE);
	ft_printf("Cause the shell to exit with a status of %sn%s.\n",
															C_MAGENTA, C_NONE);
	ft_printf("If %sn%s is omitted, the exit status is that of the last command"
											" executed.\n", C_MAGENTA, C_NONE);
	ft_printf("A trap on EXIT is executed before the shell terminates.\n");
}

/*
** @brief The function display help cd
*/

void	sh_help_cd(void)
{
	ft_printf("%scd%s [%s-L|-P%s] [%sdirectory%s]\n", CL_RED, C_NONE, C_CYAN,
													C_NONE, C_MAGENTA, C_NONE);
	ft_printf("\tChange the current working directory to %sdirectory%s.\n", C_MAGENTA, C_NONE);
	ft_printf("If %sdirectory%s is not supplied, the value of the %s$HOME%s shell ", C_MAGENTA, C_NONE, C_GREEN, C_NONE);
	ft_printf("variable is used.\n");
	ft_printf("Any additional arguments following directory are ignored.\n");
	ft_printf("The %s-P%s option means to not follow symbolic links: symbolic", C_CYAN, C_NONE);
	ft_printf(" links are resolved while cd is traversing directory and");
	ft_printf(" before processing an instance of ‘..’ in directory.\n");
	ft_printf("By default, or when the %s-L%s option is supplied, symbolic links", C_CYAN, C_NONE);
	ft_printf(" in directory are resolved after cd processes an instance of");
	ft_printf(" ‘..’ in directory.\n");
	ft_printf("If directory is ‘-’, it is converted to %s$OLDPWD%s before the", C_GREEN, C_NONE);
	ft_printf("directory change is attempted.\n");
	ft_printf("The return status is zero if the directory is successfully");
	ft_printf("changed, non-zero otherwise.\n");
}

void	sh_help_chdir(void)
{
	ft_printf("%schdir%s [%s-L|-P%s] [%sdirectory%s]\n", CL_RED, C_NONE, C_CYAN,
			  C_NONE, C_MAGENTA, C_NONE);
	ft_printf("\tChange the current working directory to %sdirectory%s.\n", C_MAGENTA, C_NONE);
	ft_printf("If %sdirectory%s is not supplied, the value of the %s$HOME%s shell ", C_MAGENTA, C_NONE, C_GREEN, C_NONE);
	ft_printf("variable is used.\n");
	ft_printf("Any additional arguments following directory are ignored.\n");
	ft_printf("The %s-P%s option means to not follow symbolic links: symbolic", C_CYAN, C_NONE);
	ft_printf(" links are resolved while chdir is traversing directory and");
	ft_printf(" before processing an instance of ‘..’ in directory.\n");
	ft_printf("By default, or when the %s-L%s option is supplied, symbolic links", C_CYAN, C_NONE);
	ft_printf(" in directory are resolved after chdir processes an instance of");
	ft_printf(" ‘..’ in directory.\n");
	ft_printf("If directory is ‘-’, it is converted to %s$OLDPWD%s before the", C_GREEN, C_NONE);
	ft_printf("directory change is attempted.\n");
	ft_printf("The return status is zero if the directory is successfully");
	ft_printf("changed, non-zero otherwise.\n");
}

/*
** @brief The function display help setenv
*/

void	sh_help_setenv(void)
{
	ft_printf("%ssetenv%s [%sname%s]=[%svalue%s]\n", CL_RED, C_NONE, C_CYAN, C_NONE, C_MAGENTA, C_NONE);
	ft_printf("Sets the environment variable %sname%s with value %svalue%s\n", C_CYAN, C_NONE, C_MAGENTA, C_NONE);
	ft_printf("If %sname%s already has a %svalue%s, then it is replaced with the new one\n", C_CYAN, C_NONE, C_MAGENTA, C_NONE);
}

/*
** @brief The function display help unsetenv
*/

void	sh_help_unsetenv(void)
{
	ft_printf("%sunsetenv%s [%sname%s]\n", CL_RED, C_NONE, C_CYAN, C_NONE);
	ft_printf("Deletes the environment variable %sname%s from env\n", C_CYAN, C_NONE);
	ft_printf("If %sname%s doesnt exists, nothing happens\n", C_CYAN, C_NONE);
	ft_printf("Optional arguments shall be passed to utility.\n");
}

/*
** @brief The function display help env
*/

void	sh_help_env(void)
{
	ft_printf("%senv%s [%s-i%s][name=value]...\t[utility [argument...]]\n",
											CL_RED, C_NONE, C_CYAN, C_NONE);
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
