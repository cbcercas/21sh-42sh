#ifndef MODDIF_ENV_C_H
#define MODDIF_ENV_C_H

# include <array/array.h>
# include "env_list_utils.h"

t_env *del_var(t_array *vars, char const *name);
t_env *set_var(t_array *vars, char const *name, char const *value);

#endif