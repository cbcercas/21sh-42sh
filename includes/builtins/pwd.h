#ifndef PWD_H
#define PWD_H

# include <core/data.h>

/**
 * @file   builtin_pwd.c
 *
 * @brief  This file contains the functions for the pwd builtin
 */


int sh_builtin_pwd(t_sh_data *data, char **args);

#endif
