/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/19 16:47:09 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins_utils.h>

t_array		*get_builtins(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(t_env))) == NULL)
		{
			log_fatal("Builtins: Can't initialise builtins array");
			ft_dprintf(STDERR_FILENO, "Builtins: Can't initialize Builtins");
			exit(1);
		}
	}
	return (e);
}

t_builtin	*sh_new_builtin(char *name, t_builtin_fn fn)
{
	t_builtin	*e;

	if (!(e = ft_memalloc(sizeof(*e))))
	{
		ft_dprintf(2, "%s: Builtin creation fail!\n", PROGNAME);
		return (NULL);
	}
	(void)name;
	e->name = strdup(name);
	e->len = ft_strlen(name);
	e->fn = fn;
	return (e);
}

t_array		*ms_add_builtin(char *name, t_builtin_fn fn)
{
	t_array		*builtins;
	t_builtin	*builtin;

	builtins = get_builtins();
	builtin = sh_new_builtin(name, fn);
	array_push(builtins, (void *)builtin);
	ft_memdel((void **)&builtin);
	return (builtins);
}

t_array		*sh_builtins_init(void)
{
	t_array	*builtins;

	builtins = get_builtins();
	if (!ms_add_builtin("exit", sh_exit))
		return (NULL);
	if (!ms_add_builtin("echo", sh_echo))
		return (NULL);
	if (!ms_add_builtin("history", sh_history))
		return (NULL);
	if (!ms_add_builtin("cd", sh_chdir))
		return (NULL);
	if (!ms_add_builtin("pwd", sh_builtin_pwd))
		return (NULL);
	if (!ms_add_builtin("help", sh_builtin_help))
		return (NULL);
	return (builtins);
}

/*
**if (!ms_add_builtin("cd", sh_chdir))
**return (NULL);
**if (!ms_add_builtin("chdir", sh_chdir))
**return (NULL);
*/
