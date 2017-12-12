/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/21 08:21:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

# include <builtins/builtin_local_var.h>
# include <builtins/builtin_env.h>
# include <builtins/builtin_pwd.h>
# include <builtins/builtin_chdir.h>
# include <builtins/builtin_history.h>
# include <builtins/builtin_help.h>

/*
** @file builtin_utils.h
**
** @brief Function prototypes for the builtins
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

typedef	int	(*t_builtin_fn)(t_sh_data *data, char **arg);

/*
** @struct  s_builtin
**
** @brief   This struct contains the info for the builtins
**
** @param   fn    function pointer
** @param   name  builtin name
** @param   len   builtin size
*/

typedef struct			s_builtin
{
	t_builtin_fn		fn;
	char				*name;
	size_t				len;
}						t_builtin;

/*
** @file   builtin_utils.c
**
** @brief  This contains all the utility functions for the builtins
*/

t_array					*get_builtins(void);
t_builtin				*sh_new_builtin(char *name, t_builtin_fn fn);
t_array					*sh_add_builtin(char *name, t_builtin_fn fn);
t_array					*sh_builtins_init(void);

/*
** @file   builtin_utils2.c
**
** @brief  This contains all the utility functions for the builtins
*/

t_builtin				*get_builtin(char *name);
char					*sh_find_quote_end(char *arg);
char					*sh_extract_str(char *arg);
t_bool					sh_is_builtin(char *name);

#endif
