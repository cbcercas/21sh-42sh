/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/17 16:06:57 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

int main(int ac, char const *av[])
{
	t_ms_data	*data;

	if (!ac || !av)
		return (1);
	if (!(data = ms_init()))
		return (1);
	ms_print_prompt();
	while (!ms_get_command(data))
		ms_print_prompt();
	ms_deinit(&data);
	return (0);
}