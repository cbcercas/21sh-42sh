//
// Created by seluj78 on 16/06/17.
//

#ifndef INC_21SH_HELP_H
# define INC_21SH_HELP_H

# include <core/data.h>
# include <core/color.h>
# include <core/main.h>//TODO: c'est pas terrible d'inclures un header qui inclue quasi tout on risque d'avoir des problem, lorsque qu'on include help.h

int sh_builtin_help(t_sh_data *data, char **args);
void sh_help_setenv(void);
void sh_help_unsetenv(void);
void sh_help_default(t_sh_data *data);
void sh_help_help(void);
void sh_help_echo(void);
void sh_help_bonus(void);
void sh_help_exit(void);
void sh_help_cd(void);
void sh_help_env(void);


#endif
