//
// Created by Jules LASNE on 6/19/17.
//

#ifndef BUILTIN_ENV_UTILS_H
#define BUILTIN_ENV_UTILS_H

# include <libft.h>
# include <logger.h>
# include <ftprintf.h>
# include <core/data.h>

void print_vars(t_array *vars);
t_array	*get_envs(void);
t_array		*get_vars(void);
void sh_free_elem_env(t_env *elem);

#endif
