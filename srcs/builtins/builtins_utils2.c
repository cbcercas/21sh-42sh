/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/19 15:16:27 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_utils.h>

t_builtin	*get_builtin(char *name)
{
	t_array		*builtins;
	t_builtin	*builtin;
	size_t		cnt;

	cnt = 0;
	builtins = get_builtins();
	while (cnt < builtins->used)
	{
		builtin = array_get_at(builtins, cnt);
		if (builtin && ft_strequ(name, builtin->name))
			return (builtin);
		cnt += 1;
	}
	return (NULL);
}

char		*sh_find_quote_end(char *arg)
{
	int		lvl;
	char	cur_q;

	lvl = 1;
	cur_q = *arg;
	arg++;
	while (*arg)
	{
		if (cur_q == *arg && lvl)
		{
			lvl -= 1;
			if (lvl)
				cur_q = (cur_q == '"') ? '`' : '"';
		}
		else if ((*arg == '"' || *arg == '`') && lvl)
		{
			cur_q = *arg;
			lvl += 1;
		}
		if (*arg == cur_q && lvl == 0)
			return (arg);
		arg++;
	}
	return ((*arg) ? arg : NULL);
}

char		*sh_extract_str(char *arg)
{
	char	*str;
	char	*q_end;

	q_end = sh_find_quote_end(arg);
	str = ft_strsub(arg, 1, q_end - arg - 1);
	return (str);
}

BOOL		sh_is_builtin(char *name)
{
	if (get_builtin(name))
		return (true);
	return (false);
}
