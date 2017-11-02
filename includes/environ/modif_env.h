#ifndef MODDIF_ENV_C_H
#define MODDIF_ENV_C_H

# include <libft.h>
# include <logger.h>
# include <ftprintf.h>
# include <core/data.h>
# include <environ/modif_env.h>
# include <environ/getter_env.h>

t_env *del_var(t_array *vars, char const *name);
t_env *
set_var(t_array *vars, char const *name, char const *value, BOOL is_export);

#endif