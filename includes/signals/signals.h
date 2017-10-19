
#ifndef SIGNALS_H
#define SIGNALS_H

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <core/prompt.h>
# include <logger.h>
# include <libft.h>
# include <ftprintf.h>
# include <core/input.h>
# include <core/tcaps.h>
# include <sys/ioctl.h>
# include <stdio.h>

void    init_signals(void *handler);
void    signals_handler(int sig);
int sh_wait(pid_t pid, int wait_flag);
void	signals_sigwinch();

#endif
