#ifndef DEINIT_H
#define DEINIT_H

# include "data.h"

/**
 * @file       deinit.c
 *
 * @brief      Functions to uninitialize the program before exiting it
 */

int sh_restore_tattr(struct termios *tattr);
void sh_deinit(t_sh_data *data);
void sh_data_free(t_sh_data *data);

#endif
