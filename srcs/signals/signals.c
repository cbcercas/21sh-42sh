
#include <signals/signals.h>

void    init_signals(void *handler)
{
	int		i;

	i = 1;
	if (!handler)
		return ;
	while (i++ < 32)
		if(i != 17 && signal(i, handler) == SIG_ERR)
			log_warn("Signal:%d no catch", i);
	log_info("Signal: Init success");
}

int		wait_sh(void)
{
	int		status;
	pid_t	pid_child;

	pid_child = wait(&status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			ft_printf("[1]    %d segmentation fault (core dumped)  %s\n", pid_child, sh_history_get_at(-1));
		else if (WTERMSIG(status) == SIGBUS)
			ft_printf("[1]    %d bus error  %s\n", pid_child, sh_history_get_at(-1));
		return (-1);
	}
	return (status);
}
