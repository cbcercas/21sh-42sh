/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_key_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:37:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/15 14:50:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

static t_key_exec	g_fn_exec[] =
{
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
	{KEY_CODE_CTRL_R, &exec_ctrl_r},
	{KEY_CODE_BACKSPACE, &exec_backspace},
	{KEY_CODE_DELETE, &exec_delete},
	{KEY_CODE_TAB, &exec_tab},
#ifdef __APPLE__

	{KEY_CODE_ALT_UARROW, &exec_alt_up},
	{KEY_CODE_ALT_DARROW, &exec_alt_down},
	{KEY_CODE_ALT_LARROW, &exec_alt_left},
	{KEY_CODE_ALT_RARROW, &exec_alt_right},
#else

	{KEY_CODE_CTRL_UARROW, &exec_alt_up},
	{KEY_CODE_CTRL_DARROW, &exec_alt_down},
	{KEY_CODE_CTRL_LARROW, &exec_alt_left},
	{KEY_CODE_CTRL_RARROW, &exec_alt_right},
#endif

	{KEY_CODE_INSERT, &exec_insert},
	{KEY_CODE_ALT_I, &exec_insert},
	{KEY_CODE_ALT_S, &exec_insert},
	{KEY_CODE_END, &exec_end},
	{KEY_CODE_ALT_C, &exec_alt_c},
	{KEY_CODE_ALT_V, &exec_alt_v},
	{KEY_CODE_HOME, &exec_start},
	{KEY_CODE_ESC, &exec_escape},
	{KEY_CODE_NONE, NULL}
};

BOOL			key_exec(t_key *key, t_window *window)
{
	int			i;

	i = 0;
	while (g_fn_exec[i].f != NULL)
	{
		if (ft_strequ(g_fn_exec[i].key_code, key->key_code))
			return (g_fn_exec[i].f(key, window));
		i++;
	}
	return (false);
}
