/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 15:18:08 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "builtins_utils.h"
#include "init.h"

t_builtins	ms_builtins_init(void)
{
	t_builtins builtins;
	builtins = ft_memalloc(sizeof(t_builtins) * last);
	builtins[0] = ms_exit;
	return (builtins);
}