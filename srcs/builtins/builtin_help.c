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
	ft_printf("#-- %s V0.42 --#\n", PROGNAME);
	ft_printf("These shell commands are defined internally.  Type `help' to");
	ft_printf("see this list.\n");
	ft_printf("Type `help name' to find out more about the function `name'.\n");
	ft_printf("\n\nA star (*) next to a name means that the command is disabled.\n");
}

int sh_builtin_help(t_sh_data *data, char **args)
{
	(void) args;
	(void) data;
	if (args[1] == NULL)
		sh_help_default(data);
	return (0);
}