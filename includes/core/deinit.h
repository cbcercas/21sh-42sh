#ifndef DEINIT_H
#define DEINIT_H


# include <core/data.h>
# include <unistd.h>
# include <termios.h>

void sh_restore_tattr(struct termios *tattr);
void sh_deinit(t_sh_data *data);
void sh_data_free(t_sh_data *data);

#endif
