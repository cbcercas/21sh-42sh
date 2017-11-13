#include <libft.h>
#include <environ/modif_env.h>
#include <environ/env_utils.h>
#include <environ/environ.h>

void	testing_local_vars_set(char *const *av)
{
	int		i;

	i = 4;
	while(av[i] && ft_strchr(av[i], '='))
	{
		set_var(get_envs(), split_var_name(av[i]), split_var_value(av[i]),
				true);
		i++;
	}
}

void	testing_local_vars_del(char *const *av)
{
	int		i;

	i = 4;
	while(av[i])
	{
		del_var(get_envs(), av[i]);
		i++;
	}
}

void	testing_local_vars(char *const *av, char **environ)
{
	init_environ(environ);
	init_local_var();
	if (av[3] && (ft_strequ(av[3], "set")))
		testing_local_vars_set(av);
	else if (av[3] && (ft_strequ(av[3], "del")))
		testing_local_vars_del(av);
	print_vars(get_envs());
	print_vars(get_vars());
	exit(0);
}