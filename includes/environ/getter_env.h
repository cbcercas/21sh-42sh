//
// Created by Jules LASNE on 6/19/17.
//

#ifndef GETTER_ENV_H
#define GETTER_ENV_H

# include <libft.h>
# include <logger.h>
# include <ftprintf.h>
# include <core/data.h>
# include <environ/builtin_env_utils.h>

char *get_var_value(t_array *vars, const char *name);
t_env *get_var(t_array *vars, const char *name);

#endif
