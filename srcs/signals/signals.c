
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
			ft_printf("[[1]    %d segmentation fault\n", pid_child);//TODO add the last command with history
		else if (WTERMSIG(status) == SIGBUS)
			ft_printf("[1]    %d bus error\n", pid_child);//TODO add the last command with history
		return (-1);
	}
	return (status);
}
