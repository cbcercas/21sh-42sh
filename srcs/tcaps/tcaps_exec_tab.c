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

#include <core/tcaps.h>

BOOL	exec_tab(const t_key *key, t_input *input)
{
	char * last_word;

	(void)key;
	last_word = autoc_get_last(input->str->s);
	



	//exec_ctrl_c(key, input);
	return (false);
}