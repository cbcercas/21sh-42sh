
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

# define ISSIGQUIT(x) (((x >= 1 && x <= 17) || x == 23 || x == 24 || (x >= 26 && x <= 31)) && x != SIGWINCH)

void    init_signals(void *handler);
void    signals_handler(int sig);
int    wait_sh(void);
void	signals_sigwinch();

#endif
