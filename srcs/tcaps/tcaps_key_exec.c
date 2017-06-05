/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_key_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:37:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/05 15:30:27 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	key_exec(t_key *key, t_input *input)
{
	static t_key_exec	fn_exec[] = {
		{KEY_CODE_RARROW, &exec_arrow_right},
		{KEY_CODE_LARROW, &exec_arrow_left},
		{KEY_CODE_DARROW, &exec_arrow_down},
		{KEY_CODE_UARROW, &exec_arrow_up},
		{KEY_CODE_CTRL_C, &exec_ctrl_c},
		{KEY_CODE_CTRL_D, &exec_ctrl_d},
		{KEY_CODE_CTRL_Z, &exec_ctrl_z},
		{KEY_CODE_CTRL_A, &exec_ctrl_a},
		{KEY_CODE_CTRL_E, &exec_ctrl_e},
		{KEY_CODE_CTRL_L, &exec_ctrl_l},
		{KEY_CODE_CTRL_R, &exec_ctrl_r},
		{KEY_CODE_ENTER, &exec_ctrl_j},
		{KEY_CODE_BACKSPACE, &exec_backspace},
		{KEY_CODE_DELETE, &exec_delete},
		{KEY_CODE_TAB, &exec_tab},
		{KEY_CODE_NONE, NULL}
	};
	int				i;

	i = -1;
	while (fn_exec[++i].f != NULL)
		if (ft_strequ(fn_exec[i].key_code, key->key_code))
			return (fn_exec[i].f(key, input));
	return (false);
}
