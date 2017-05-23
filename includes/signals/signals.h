
#ifndef SIGNALS_H
#define SIGNALS_H

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <core/prompt.h>
# include <logger/logger.h>
# include <libft.h>
# include <ft_printf/libftprintf.h>

void    init_signals(void *handler);
void    signals_handler(int sig);
int    wait_sh();

#endif