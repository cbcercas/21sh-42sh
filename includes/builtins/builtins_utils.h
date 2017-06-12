/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/08 11:02:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_UTILS_H
# define BUILTINS_UTILS_H
# include <core/data.h>
# include <builtins/exit.h>
# include <builtins/echo.h>
# include <builtins/chdir.h>
# include <builtins/builtin_history.h>

typedef 	int (*t_builtin_fn)(t_sh_data *data, char **arg);

typedef struct			s_builtin
{
	t_builtin_fn		fn;
	char				*name;
	size_t				len;
}						t_builtin;

t_array					*sh_builtins_init(void);
t_builtin				*get_builtin(char *name);
t_bool					sh_is_builtin(char *name);
char					*sh_extract_str(char *arg);

#endif
