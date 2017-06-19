//
// Created by Jules LASNE on 6/19/17.
//

#ifndef BUILTIN_ENV_UTILS_H
#define BUILTIN_ENV_UTILS_H

# include <libft.h>
# include <logger.h>
# include <ftprintf.h>
# include <core/data.h>

void    sh_print_env(void);
t_array	*sh_get_envs(void);

#endif
