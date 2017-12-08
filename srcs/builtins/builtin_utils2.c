/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/19 15:16:27 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_utils.h>

/*
** @brief Gets a builtin by its name from the array
**
** @param name The builtin's name
**
** @return Returns the array containing the builtin's info
*/

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

/*
** @brief Checks if given name is a builtin
**
** @param name Name to be checked
**
** @return Returns `true` if name is a builtin, `false` otherwise
*/

BOOL		sh_is_builtin(char *name)
{
	if (get_builtin(name))
		return (true);
	return (false);
}
