/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:47:05 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/30 13:48:15 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tcaps_test.h>
BOOL	exec_tab(const t_key *key)
{
	(void)key;
	write(1, "User pressed tab\n", 16);
	exec_ctrl_c(key);
	return (false);
}


