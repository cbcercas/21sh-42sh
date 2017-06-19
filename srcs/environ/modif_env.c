
#include <environ/modif_env.h>

t_env	*sh_setenv(char const *name, char const *value)
{
	t_array	*envs;
	t_env	*env;

	if ((env = sh_getenv(name)) != NULL)
	{
		ft_strdel(&env->value);
		env->value = ft_strdup(value);
	}
	else
	{
		envs = sh_get_envs();
		if ((env = env_new(ft_strdup(name), ft_strdup(value))) != NULL)
		{
			array_push(envs, (void *)env);
			ft_memdel((void**)&env);
		}
	}
	return (NULL);
}

t_env    *sh_delenv(char const *name)
{
	t_array		*envs;
	t_env			*e;
	size_t		i;

	i = 0;
	envs = sh_get_envs();
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		if (ft_strequ(e->name, name) && e->name)
			break;
		i++;
	}
	if (i >= envs->used)
		log_warn("Environ: can't find \"%s\" variables ", name);
	else
		envs = array_remove_at(envs, i, NULL);
	return (NULL);
}
