#ifndef BUILTIN_ENVIRON_H
#define BUILTIN_ENVIRON_H

# include <libft.h>
# include <logger.h>
# include <ftprintf.h>
# include <core/data.h>
# include <environ/getter_env.h>
int     sh_builtin_setenv(t_sh_data *data, char **args);
int     sh_builtin_unsetenv(t_sh_data *data, char **args);

#endif
