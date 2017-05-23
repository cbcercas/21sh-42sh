
#include <signals/signals.h>

void    init_signals(void *handler)
{
	if (!handler)
		return ;
	if(signal(SIGINT, handler) == SIG_ERR)
		log_warn("SIGINT no catch");
	if(signal(SIGSEGV, handler) == SIG_ERR)
		log_warn("SIGSEGV no catch");
	if(signal(SIGBUS, handler) == SIG_ERR)
		log_warn("SIGBUS no catch");
	log_info("Signal: Init success");
}

void    signals_handler(int sig)
{
	if(sig == SIGINT)
	{
		log_info("Signal: User pressed Ctrl+C.");
		ft_putstr("\n");
		sh_print_prompt();
		return;
	}
	if(sig == SIGSEGV)
	{
		log_info("Signal: Segfault.");
		ft_putstr("\nOups... Segfault du shell :(\n");
		exit(42);
	}
	if(sig == SIGBUS)
	{
		log_info("Signal: Bus error.");
		ft_putstr("\nOups... Bus Error su shell :(\n");
		exit(42);
	}
}

int		wait_sh()
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
	}
	return (status);
}
