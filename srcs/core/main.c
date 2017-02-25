/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 16:24:34 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/main.h>

int main(int ac, char const *av[])
{
	t_ms_data	*data;
	char		*input;
	char		**command;

	if (!ac || !av)
		return (1);
	if (!(data = ms_init()))
		return (1);
	while (true)
	{
		ms_print_prompt();
		input = ms_get_line();
		if ((command = ms_get_command(input)))
			ms_exec_command(command, data->env);
	}
	ms_deinit(&data);
	return (0);
}