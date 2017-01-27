/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/27 02:10:14 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

int main(int ac, char const *av[])
{
	t_ms_data	*data;
	char		*input;

	if (!ac || !av)
		return (1);
	if (!(data = ms_init()))
		return (1);
	while (true)
	{
		ms_print_prompt();
		input = ms_get_line();
		ft_printf("input: %s\n", input);
	}
	ms_deinit(&data);
	return (0);
}