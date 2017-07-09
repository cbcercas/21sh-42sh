#include <core/deinit.h>

void		sh_data_free(t_sh_data *data)
{
    (void)data;
    return;
}

/*
** sh_data_free
**TODO: Free local and apps environment variables.
**TODO: Free correctly data.
*/

int sh_restore_tattr(struct termios *tattr)
{
	struct termios term;

	term = *tattr;
	free(tattr);
	tattr = NULL;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) < 0)
    {
	    ft_printf("%s: STDIO error while", PROGNAME);
	    ft_printf(" restoring terminal attributes\n");
	    return (1);
    }
    return (0);
}

/*
** TODO: Do something with the return values
*/
void			sh_deinit(t_sh_data *data)
{
    sh_restore_tattr(data->tattr);
    sh_data_free(data);
}
