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

t_array	*sh_get_envs(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(t_env))) == NULL)
		{
			log_fatal("Environ: can't initialise environment array");
			ft_dprintf(STDERR_FILENO, "Environ: can't initialise environment variables");
			exit(1);
		}
	}
	return (e);
}

t_array	*sh_init_environ(void)
{
	t_array	*envs;
	t_env	*env;

	if ((envs = sh_get_envs()) != NULL)
	{
		while (*environ) {
			if ((env = env_new(split_env_name(*environ),
							   split_env_value(*environ))) != NULL) {
				array_push(envs, (void *) env);
				ft_memdel((void **) &env);
			}
			environ++;
		}
	}
	return (envs);
}

char	**sh_tenv_to_tab(void)
{
	t_array	*envs;
	t_env	*env;
	int		cnt;
	char	**env_tab;
	size_t	i;

	envs = sh_get_envs();
	env_tab = ft_memalloc(sizeof(*env_tab) * envs->used);
	i = 0;
	while ((env = (t_env *)array_get_at(envs, i)) != NULL)
	{
		env_tab[i] = ft_strjoin(env->name, "=");
		env_tab[i] = ft_strjoincl(env_tab[cnt], env->value, 1);
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}