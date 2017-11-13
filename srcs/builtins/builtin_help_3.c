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

#include <builtins/help.h>

/*
**TODO: ADD MORE COLORS
*/

int		sh_builtin_help_helper(char **args)
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

void sh_help_history(void)
{
	ft_printf("\thistory\n");
	ft_printf("\t\thistory [n]\n");
	ft_printf("\thistory -c\n");
	ft_printf("\thistory -d offset\n");
	ft_printf("\t\thistory [-anrw] [filename]\n");
	ft_printf("\thistory -ps arg\n\n");
	ft_printf("With no options, display the history list with line numbers.\n");
	ft_printf("\tOptions, if supplied, have the following meanings:\n");
	ft_printf("-c\n");
	ft_printf("\tClear the history list. This may be combined with the other "
					  "options to replace the history list completely.\n");
	ft_printf("-d offset\n");
	ft_printf("\tDelete the history entry at position offset. offset should"
					  " be specified as it appears when the history is "
					  "displayed.\n");
	ft_printf("-a\n");
	ft_printf("\tAppend the new history lines to the history file. These "
					  "are history lines entered since the beginning of the "
					  "current Bash session, but not already appended to the "
					  "history file.\n");
	ft_printf("-n\n");
	ft_printf("\tAppend the history lines not already read from the history "
					  "file to the current history list. These are lines appended"
					  " to the history file since the beginning of the current Bash session.\n");
	sh_help_history_helper();
}

void	sh_help_history_helper(void)
{
	ft_printf("-r\n");
	ft_printf("\tRead the history file and append its contents to the history"
					  " list.\n");
	ft_printf("-w\n");
	ft_printf("\tWrite out the current history list to the history file.\n");
	ft_printf("-p\n");
	ft_printf("\tPerform history substitution on the args and display the "
					  "result on the standard output, without storing the "
					  "results in the history list.\n");
	ft_printf("-s\n");
	ft_printf("\tThe args are added to the end of the history list as a "
					  "single entry.\n");
	ft_printf("\n\t\tWhen any of the -w, -r, -a, or -n options is used, if "
					  "filename is given, then it is used as the history file"
					  ". If not, then the value of the HISTFILE variable is "
					  "used.");
}