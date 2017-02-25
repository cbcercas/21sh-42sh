/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:20:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 19:19:03 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
extern char **environ;
#include <environ/environ.h>

t_env	*ms_copy_environ(void)
{
	t_env	*head;
	t_env	*e;

	head = NULL;
	while(*environ)
	{
		if (!head)
		{
			if (!(head = ms_new_env(ms_getenv_name(*environ), ms_getenv_value(*environ))))
				// TODO add error function malloc
				return (NULL);
			e = head;
		}
		else if (e && !(e->next = ms_new_env(ms_getenv_name(*environ), ms_getenv_value(*environ))))
			// TODO add error function malloc
			return (NULL);
		else
			e = e->next;
		environ++;
	}
	return (head);
}

char	*ms_getenv(t_env const *env, const char *name)
{
	t_env const	*e;

	e = env;
	while (e && ft_strcmp(e->name, name))
	{
		e = e->next;
	}
	if (e)
		return (e->value);
	return (NULL);
}

t_env	*ms_setenv(t_env *env, char const *name, char const *value)
{
	t_env	*e;

	e = env;
	while (e)
	{
		if (ft_strequ(e->name, name))
		{
			ft_strdel(&e->value);
			e->value = ft_strdup(value);
			return (e);
		}
		else if (!e->next)
		{
			e->next = ms_new_env(ft_strdup(name), ft_strdup(value));
			return (e->next);
		}
		else
			e = e->next;
	}
	return (NULL);
}

#include <ft_printf/libftprintf.h>
char	**ms_tenv_to_tab(t_env const *env)
{
	t_env	const *e;
	int		cnt;
	char	**env_tab;

	e = env;
	cnt = 0;
	while (e)
	{
		cnt += 1;
		e = e->next;
	}
	e = env;
	env_tab = ft_memalloc(sizeof(*env_tab) * (cnt + 1));
	cnt = 0;
	while (e)
	{
		env_tab[cnt] = ft_strjoin(e->name, "=");
		env_tab[cnt] = ft_strjoincl(env_tab[cnt], e->value, 1);
		e = e->next;
		cnt += 1;
	}
	env_tab[cnt] = NULL;
	return (env_tab);
}