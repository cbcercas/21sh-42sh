
#ifndef SIGNALS_H
# define SIGNALS_H

void    init_signals(void *handler);
void    signals_handler(int sig);
int    wait_sh(void);
void	signals_sigwinch();

#endif
