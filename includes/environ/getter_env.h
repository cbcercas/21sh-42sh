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

char	*sh_getenv_value(const char *name);
t_env	*sh_getenv(char const *name);

#endif
