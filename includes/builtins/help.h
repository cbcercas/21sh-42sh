//
// Created by seluj78 on 16/06/17.
//

#ifndef INC_21SH_HELP_H
# define INC_21SH_HELP_H

# include <core/data.h>

/**
 * @file   builtin_help.c
 *
 * @brief  Contains the functions for help display
 */

int sh_builtin_help(t_sh_data *data, char **args);
void sh_help_default(t_sh_data *data);
void sh_help_help(void);
void sh_help_echo(void);
void sh_help_bonus(void);

/**
 * @file   builtin_help_2.c
 *
 * @brief  Contains the functions for help display
 */

void sh_help_exit(void);
void sh_help_cd(void);
void sh_help_env(void);
void sh_help_setenv(void);
void sh_help_unsetenv(void);


#endif
