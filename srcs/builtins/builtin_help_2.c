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
** @brief Displays help for the exit builtin
*/

void	sh_help_exit(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%sexit%s [%sn%s]\n", (col) ? CL_RED : "", C_NONE,
												(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\tCause the shell to exit with a status of %sn%s.\n",
												(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("If %sn%s is omitted, the exit status is that of the last "
						"command executed.\n", (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("A trap on %sEXIT%s is executed before the shell terminates.\n",
												(col) ? C_GREEN : "", C_NONE);
}

/*
** @brief Displays the help for the cd builtin
*/

void	sh_help_cd(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%scd%s [%s-L|-P%s] [%sdirectory%s]\n", (col) ? CL_RED : "",
		C_NONE, (col) ? C_CYAN : "", C_NONE, (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\tChange the current working directory to %sdirectory%s.\n",
											(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("If %sdirectory%s is not supplied, the value of the "
					"%s$HOME%s shell ", (col) ? C_MAGENTA : "", C_NONE,
					(col) ? C_GREEN : "", C_NONE);
	ft_printf("variable is used.\n");
	ft_printf("Any additional arguments following directory are ignored.\n");
	ft_printf("The %s-P%s option means to not follow symbolic links: symbolic",
												(col) ? C_CYAN : "", C_NONE);
	ft_printf(" links are resolved while cd is traversing directory and");
	ft_printf(" before processing an instance of ‘..’ in directory.\n");
	ft_printf("By default, or when the %s-L%s option is supplied, symbolic "
										"links", (col) ? C_CYAN : "", C_NONE);
	ft_printf(" in directory are resolved after cd processes an instance of");
	ft_printf(" ‘..’ in directory.\n");
	ft_printf("If directory is ‘-’, it is converted to %s$OLDPWD%s before the",
												(col) ? C_GREEN : "", C_NONE);
	ft_printf("directory change is attempted.\n");
	ft_printf("The return status is zero if the directory is successfully");
	ft_printf("changed, non-zero otherwise.\n");
}

/*
** @brief Displays the help for the chdir builtin
*/

void	sh_help_chdir(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%schdir%s [%s-L|-P%s] [%sdirectory%s]\n", (col) ? CL_RED : "",
		C_NONE, (col) ? C_CYAN : "", C_NONE, (col) ? C_MAGENTA : "", C_NONE);
	ft_printf("\tChange the current working directory to %sdirectory%s.\n",
											(col) ? C_MAGENTA : "", C_NONE);
	ft_printf("If %sdirectory%s is not supplied, the value of the "
		"%s$HOME%s shell variable is used.\n", (col) ? C_MAGENTA : "", C_NONE,
					(col) ? C_GREEN : "", C_NONE);
	ft_printf("Any additional arguments following directory are ignored.\n");
	ft_printf("The %s-P%s option means to not follow symbolic links: symbolic",
												(col) ? C_CYAN : "", C_NONE);
	ft_printf(" links are resolved while chdir is traversing directory and");
	ft_printf(" before processing an instance of ‘..’ in directory.\n");
	ft_printf("By default, or when the %s-L%s option is supplied, symbolic "
										"links", (col) ? C_CYAN : "", C_NONE);
	ft_printf(" in directory are resolved after chdir processes "
															"an instance of");
	ft_printf(" ‘..’ in directory.\n");
	ft_printf("If directory is ‘-’, it is converted to %s$OLDPWD%s before the",
												(col) ? C_GREEN : "", C_NONE);
	ft_printf("directory change is attempted.\n");
	ft_printf("The return status is zero if the directory is successfully");
	ft_printf("changed, non-zero otherwise.\n");
}

/*
** @brief Displays the help for the setenv builtin
*/

void	sh_help_setenv(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%ssetenv%s [%sname%s]=[%svalue%s]\n", (col) ? CL_RED : "",
		(col) ? C_NONE : "", (col) ? C_CYAN : "", (col) ? C_NONE : "",
								(col) ? C_MAGENTA : "", (col) ? C_NONE : "");
	ft_printf("Sets the environment variable %sname%s with value %svalue%s\n",
				(col) ? C_CYAN : "", (col) ? C_NONE : "",
								(col) ? C_MAGENTA : "", (col) ? C_NONE : "");
	ft_printf("If %sname%s already has a %svalue%s, then it is replaced with "
"the new one\n", (col) ? C_CYAN : "", (col) ? C_NONE : "",
								(col) ? C_MAGENTA : "", (col) ? C_NONE : "");
}

/*
** @brief Displays the help for the unsetenv builtin
*/

void	sh_help_unsetenv(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%sunsetenv%s [%sname%s]\n", (col) ? CL_RED : "",
				(col) ? C_NONE : "", (col) ? C_CYAN : "", (col) ? C_NONE : "");
	ft_printf("Deletes the environment variable %sname%s from env\n",
									(col) ? C_CYAN : "", (col) ? C_NONE : "");
	ft_printf("If %sname%s doesnt exists, nothing happens\n",
									(col) ? C_CYAN : "", (col) ? C_NONE : "");
}
