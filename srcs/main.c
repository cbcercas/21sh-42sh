/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 11:48:26 by chbravo-         ###   ########.fr       */
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
	return (0);
}