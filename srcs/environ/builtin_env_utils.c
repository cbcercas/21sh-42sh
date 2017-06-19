# include <environ/builtin_env_utils.h>

void	sh_print_env()
{
	t_array	*envs;
	t_env	*e;
	size_t	i;

	envs = sh_get_envs();
	i = 0;
	while (i < envs->used)
	{
		e = (t_env *)array_get_at(envs, i);
		ft_printf("%s=%s\n", e->name, e->value);
		i++;
	}
}

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