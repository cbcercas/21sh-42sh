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

static void		init_key_exec_3(t_key_exec *fn_exec)
{
	fn_exec[25].key_code = KEY_CODE_ALT_C;
	fn_exec[25].f = &exec_alt_c;
	fn_exec[26].key_code = KEY_CODE_ALT_V;
	fn_exec[26].f = &exec_alt_v;
	fn_exec[27].key_code = KEY_CODE_HOME;
	fn_exec[27].f = &exec_start;
	fn_exec[28].key_code = KEY_CODE_ESC;
	fn_exec[28].f = &exec_escape;
	fn_exec[29].key_code = KEY_CODE_NONE;
	fn_exec[29].f = NULL;
}

static void		init_key_exec_2(t_key_exec *fn_exec)
{
	fn_exec[13].key_code = KEY_CODE_CTRL_R;
	fn_exec[13].f = &exec_ctrl_r;
	fn_exec[14].key_code = KEY_CODE_BACKSPACE;
	fn_exec[14].f = &exec_backspace;
	fn_exec[15].key_code = KEY_CODE_DELETE;
	fn_exec[15].f = &exec_delete;
	fn_exec[16].key_code = KEY_CODE_TAB;
	fn_exec[16].f = &exec_tab;
#ifdef __APPLE__
	fn_exec[17].key_code = KEY_CODE_ALT_UARROW;
	fn_exec[18].key_code = KEY_CODE_ALT_DARROW;
	fn_exec[19].key_code = KEY_CODE_ALT_LARROW;
	fn_exec[20].key_code = KEY_CODE_ALT_RARROW;
#else
	fn_exec[17].key_code = KEY_CODE_CTRL_UARROW;
	fn_exec[18].key_code = KEY_CODE_CTRL_DARROW;
	fn_exec[19].key_code = KEY_CODE_CTRL_LARROW;
	fn_exec[20].key_code = KEY_CODE_CTRL_RARROW;
#endif
	fn_exec[17].f = &exec_alt_up;
	fn_exec[18].f = &exec_alt_down;
	fn_exec[19].f = &exec_alt_left;
	fn_exec[20].f = &exec_alt_right;
	fn_exec[21].key_code = KEY_CODE_INSERT;
	fn_exec[21].f = &exec_select;
	fn_exec[22].key_code = KEY_CODE_ALT_I;
	fn_exec[22].f = &exec_select;
	fn_exec[23].key_code = KEY_CODE_ALT_S;
	fn_exec[23].f = &exec_select;
	fn_exec[24].key_code = KEY_CODE_END;
	fn_exec[24].f = &exec_end;
	init_key_exec_3(fn_exec);
}

static void		init_key_exec(t_key_exec *fn_exec)
{
	fn_exec[1].key_code = KEY_CODE_RARROW;
	fn_exec[1].f = &exec_arrow_right;
	fn_exec[2].key_code = KEY_CODE_LARROW;
	fn_exec[2].f = &exec_arrow_left;
	fn_exec[3].key_code = KEY_CODE_DARROW;
	fn_exec[3].f = &exec_arrow_down;
	fn_exec[4].key_code = KEY_CODE_UARROW;
	fn_exec[4].f = &exec_arrow_up;
	fn_exec[5].key_code = KEY_CODE_CTRL_C;
	fn_exec[5].f = &exec_ctrl_c;
	fn_exec[6].key_code = KEY_CODE_CTRL_D;
	fn_exec[6].f = &exec_ctrl_d;
	fn_exec[7].key_code = KEY_CODE_CTRL_Z;
	fn_exec[7].f = &exec_ctrl_z;
	fn_exec[8].key_code = KEY_CODE_CTRL_A;
	fn_exec[8].f = &exec_ctrl_a;
	fn_exec[9].key_code = KEY_CODE_CTRL_E;
	fn_exec[9].f = &exec_ctrl_e;
	fn_exec[10].key_code = KEY_CODE_CTRL_L;
	fn_exec[10].f = &exec_ctrl_l;
	fn_exec[11].key_code = KEY_CODE_CTRL_R;
	fn_exec[11].f = &exec_ctrl_r;
	fn_exec[12].key_code = KEY_CODE_ENTER;
	fn_exec[12].f = &exec_ctrl_j;
	init_key_exec_2(fn_exec);
}

BOOL			key_exec(t_key *key, t_input *input)
{
	static t_key_exec	fn_exec[30];
	static t_key_exec	*init = NULL;
	int					i;

	if (!init)
	{
		init_key_exec(fn_exec);
		init = fn_exec;
	}
	i = 1;
	while (fn_exec[i].f != NULL)
	{
		if (ft_strequ(fn_exec[i].key_code, key->key_code))
			return (fn_exec[i].f(key, input));
		i++;
	}
	return (false);
}
