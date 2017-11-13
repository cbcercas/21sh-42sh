#include <signals/signals.h>
#include <ftprintf.h>
#include <logger.h>
#include <array/array.h>
#include <signal.h>
#include <environ/getter_env.h>
#include <environ/env_utils.h>

pid_t get_pid_child(pid_t pid_op)
{
	static	pid_t		pid = 0;

	if (pid_op > 0)
		pid = pid_op;
	return (pid);
}


t_array		*get_pids_child(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(
									  t_pids))) == NULL)
		{
			log_fatal("get_pids_child: can't initialise pids child array");
			ft_dprintf(STDERR_FILENO, "get_pids_child: can't initialise pids childs\
					variables\n");
			exit(1);
		}
	}
	return (e);
}

int		kill_childs(int sig)
{
	t_array		*e;

	e = get_pids_child();
	if (!e)
		return (EXIT_FAILURE);
	while (0 < e->used)
	{
		log_dbg3("kill pid = %d (SHLVL = %s)\n", ((t_pids*)array_get_at(e, 0))->pid,
				  get_var_value(get_envs(), "SHLVL"));
		kill(((t_pids*)array_get_at(e, 0))->pid, sig);
		array_remove_at(e, 0, NULL);
	}
	return (EXIT_SUCCESS);
}

void	remove_pid_child(int pid_child)
{
	size_t		i;
	t_array		*e;

	i = 0;
	e = get_pids_child();
	while (i < e->used)
	{
		if (((t_pids*)array_get_at(e, 0))->pid == pid_child)
			break ;
		i++;
	}
	if (i >= e->used)
		log_warn("PID: can't find \"%d\" variables ", pid_child);
	else
	{
		log_dbg3("PID: remove pid : %d", pid_child);
		array_remove_at(e, i, NULL);
	}
}

void	remove_useless(void)
{
	size_t		i;
	t_array		*e;

	i = 0;
	e = get_pids_child();
	if (!e)
		return ;
	while (i < e->used)
	{
		if (kill(((t_pids*)array_get_at(e, 0))->pid, 0) == -1)
			array_remove_at(e, i, NULL);
		else
			i++;
	}
}
