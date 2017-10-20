#ifndef BUILTIN_LOCAL_VAR_H
# define BUILTIN_LOCAL_VAR_H

# include <core/data.h>

int	builtin_unset(t_sh_data *data, char **argv);
int	builtin_export(t_sh_data *data, char **argv);

#endif