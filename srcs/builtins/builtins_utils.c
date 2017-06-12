/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/12 20:07:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtins_utils.h>

t_array				*get_builtins(void)
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

static t_builtin	*sh_new_builtin(char *name, t_builtin_fn fn)
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

static t_array	*ms_add_builtin(char *name, t_builtin_fn fn)
{
	t_array		*builtins;
	t_builtin	*builtin;

	builtins = get_builtins();
	builtin = sh_new_builtin(name, fn);
	array_push(builtins, (void *) builtin);
	ft_memdel((void **) &builtin);
	return (builtins);
}


t_array			*sh_builtins_init(void)
{
	t_array	*builtins;

	builtins = get_builtins();
	if (!ms_add_builtin("exit", sh_exit))
		return (NULL);
	if (!ms_add_builtin("echo", sh_echo))
		return (NULL);
	/*if (!ms_add_builtin("cd", sh_chdir))
		return (NULL);
	if (!ms_add_builtin("chdir", sh_chdir))
		return (NULL);*/
	if (!ms_add_builtin("history", sh_history))
		return (NULL);
	return (builtins);
}


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

t_bool sh_is_builtin(char *name)
{
	if (get_builtin(name))
		return (true);
	return (false);
}

static char	*sh_find_quote_end(char *arg)
{
	int	lvl;
	char cur_q;

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

char	*sh_extract_str(char *arg)
{
	char	*str;
	char	*q_end;

	q_end = sh_find_quote_end(arg);
	str = ft_strsub(arg, 1, q_end - arg - 1);
	return (str);
}
