/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env_u.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 14:46:11 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_env.h>

t_env			*sh_builtin_env_delenv(char const *name, t_array *envs)
{
	t_env		*e;
	size_t		i;

	i = 0;
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		if (ft_strequ(e->name, name) && e->name)
			break ;
		i++;
	}
	if (i >= envs->used)
		log_warn("Environ: can't find \"%s\" variables ", name);
	else
		envs = array_remove_at(envs, i, NULL);
	return (NULL);
}

t_env			*builtin_env_new_env(t_env *env)
{
	t_env	*e;

	if ((e = secu_malloc(sizeof(*e))) == NULL)
	{
		log_fatal("Environ: can't create new environment varibles");
		ft_dprintf(STDERR_FILENO, "Builtins Env: can't create new environment \
				varibles\n");
	}
	else if ((e->name = ft_strdup(env->name)) == NULL)
	{
		log_fatal("Environ: can't create new environment varibles");
		ft_dprintf(STDERR_FILENO, "Environ: can't create new environment \
				varibles\n");
		ft_memdel((void**)&e);
	}
	else
		e->value = ft_strdup(env->value);
	return (e);
}

t_array			*clone_env(t_array *tmp)
{
	t_array	*envs;
	t_env	*env;
	size_t	i;

	envs = sh_get_envs();
	if (!envs)
		return (tmp);
	i = 0;
	while (i < envs->used)
	{
		if (!(env = builtin_env_new_env((t_env *)array_get_at(envs, i))))
			return (NULL);
		array_push(tmp, (void *)env);
		i++;
	}
	return (tmp);
}

t_array			*sh_builtin_env_u(t_array *tmp, char **argv)
{
	if (tmp == NULL)
		return (NULL);
	tmp = clone_env(tmp);
	if (g_optind != -1 && argv[g_optind])
	{
		sh_builtin_env_delenv(argv[g_optind], tmp);
		g_optind++;
	}
	return (tmp);
}
