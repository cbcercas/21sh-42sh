#ifndef MODDIF_ENV_C_H
#define MODDIF_ENV_C_H

# include <libft.h>
# include <logger.h>
# include <ftprintf.h>
# include <core/data.h>
# include <environ/modif_env.h>
# include <environ/getter_env.h>

t_env    *sh_delenv(char const *name);
t_env	*sh_setenv(char const *name, char const *value);

#endif