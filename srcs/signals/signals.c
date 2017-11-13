
#include <signals/signals.h>
#include <signal.h>
#include <logger.h>
#include <sys/wait.h>
#include <ftprintf.h>
#include <history/history.h>

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

int sh_wait(pid_t pid, int wait_flag)
{
	int		status;
	pid_t	pid_child;

	status = 0;
	pid_child = waitpid(pid, &status, wait_flag);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			ft_dprintf(STDERR_FILENO, "[1]    %d segmentation fault (core "
					"dumped)  %s\n", pid_child, sh_history_get_at(-1));
		else if (WTERMSIG(status) == SIGBUS)
			ft_dprintf(STDERR_FILENO, "[1]    %d bus error  %s\n", pid_child,
					  sh_history_get_at(-1));
		return (status);
	}
	remove_pid_child(pid);
	return (status);
}

BOOL	*get_stop(void)
{
	static BOOL		stop = true;
	return (&stop);
}