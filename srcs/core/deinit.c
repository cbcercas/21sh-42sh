#include <core/deinit.h>

void		sh_data_free(t_sh_data *data)
{
    //TODO free envs
    (void)data;
    return;
}

void sh_restore_tattr(struct termios *tattr)
{
    if (tcsetattr(STDIN_FILENO, TCSANOW, tattr) < 0)
    {
        //TODO: perror("stdin");
        return;
    }
    return;
}

void			sh_deinit(t_sh_data *data)
{
    //TODO: Store tattr dans data
    sh_data_free(data);
    //default_terminal_mode();
}
