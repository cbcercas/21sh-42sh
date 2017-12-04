/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:19:22 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:20:36 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_help.h>

/*
** @brief The function called when help is the next of sh_builtin_help()
** @param argv The args passed to help
**
** @return Returns the ret value of help
*/

int			sh_builtin_help_helper(char **args)
{
	if (ft_strequ(args[1], "bonus"))
		sh_help_bonus();
	else if (ft_strequ(args[1], "history"))
		sh_help_history();
	else
	{
		ft_printf("%s: Couldn't find the help wanted for %s\n",\
		PROGNAME, args[1]);
		return (1);
	}
	return (0);
}

/*
** @brief The function display help history
*/

void		sh_help_history(void)
{
	ft_printf("%shistory%s [n] [cdanrwps]\n", CL_RED, C_NONE);
	ft_printf("\thistory\n");
	ft_printf("\t\thistory [n]\n");
	ft_printf("\thistory %s-c%s\n", C_CYAN, C_NONE);
	ft_printf("\thistory %s-d%s offset\n", C_CYAN, C_NONE);
	ft_printf("\t\thistory [-anrw] [filename]\n");
	ft_printf("\thistory %s-ps%s arg\n\n", C_CYAN, C_NONE);
	ft_printf("With no options, display the history list with line numbers.\n");
	ft_printf("\tOptions, if supplied, have the following meanings:\n");
	ft_printf("%s-c%s\n", C_CYAN, C_NONE);
	ft_printf("\tClear the history list. This may be combined with the other "
					"options to replace the history list completely.\n");
	ft_printf("%s-d%s offset\n", C_CYAN, C_NONE);
	ft_printf("\tDelete the history entry at position offset. offset should"
					" be specified as it appears when the history is "
					"displayed.\n");
	ft_printf("%s-a%s\n", C_CYAN, C_NONE);
	ft_printf("\tAppend the new history lines to the history file. These "
					"are history lines entered since the beginning of the "
					"current Bash session, but not already appended to the "
					"history file.\n");
	ft_printf("%s-n%s\n", C_CYAN, C_NONE);
	sh_help_history_helper();
}

/*
** @brief The function display help history following
*/

void		sh_help_history_helper(void)
{
	ft_printf("\tAppend the history lines not already read from the history "
					"file to the current history list. These are lines "
					"appended"
					" to the history file since the beginning of the current "
					"Bash session.\n");
	ft_printf("%s-r%s\n", C_CYAN, C_NONE);
	ft_printf("\tRead the history file and append its contents to the history"
					" list.\n");
	ft_printf("%s-w%s\n", C_CYAN, C_NONE);
	ft_printf("\tWrite out the current history list to the history file.\n");
	ft_printf("%s-p%s\n", C_CYAN, C_NONE);
	ft_printf("\tPerform history substitution on the args and display the "
					"result on the standard output, without storing the "
					"results in the history list.\n");
	ft_printf("%s-s%s\n", C_CYAN, C_NONE);
	ft_printf("\tThe args are added to the end of the history list as a "
					"single entry.\n");
	ft_printf("\n\t\tWhen any of the -w, -r, -a, or -n options is used, if "
					"filename is given, then it is used as the history file"
					". If not, then the value of the HISTFILE variable is "
					"used.\n");
}

/*
** @brief The function display help pwd
*/

void		sh_help_pwd(void)
{
	ft_printf("%spwd%s [%s-L|-P%s] [directory]\n",
											CL_RED, C_NONE, C_CYAN, C_NONE);
	ft_printf("The pwd utility shall write to standard output an absolute"
					"pathname of the current working directory, which does not"
					" contain the filenames dot or dot-dot.\n");
	ft_printf("%s-L%s\tIf the PWD environment variable contains an absolute"
					" pathname of the current directory that does not contain"
					" the filenames dot or dot-dot, pwd shall write this"
					" pathname to standard output.Otherwise, the -L option"
					" shall behave as the %s-P%s option.\n",
											C_CYAN, C_NONE, C_CYAN, C_NONE);
	ft_printf("%s-P%s\tThe pathname written to standard output shall not "
					"contain any components that refer to files of type "
										"symbolic link. \n", C_CYAN, C_NONE);
	ft_printf("If both %s-L%s and %s-P%s are specified, the last one shall "
					"apply. If neither %s-L%s nor %s-P%s is specified, the pwd "
					"utility shall behave as if %s-L%s had been specified.\n",
			C_CYAN, C_NONE, C_CYAN, C_NONE, C_CYAN, C_NONE, C_CYAN,
			C_NONE, C_CYAN, C_NONE);
}

/*
** TODO export and unset + Redo printfs
*/
