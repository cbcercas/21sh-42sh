/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/26 14:10:22 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUILTINS_UTILS_H
# define BUILTINS_UTILS_H
# include <core/data.h>
# include <builtins/exit.h>
# include <builtins/echo.h>
# include <builtins/chdir.h>

typedef 	int (*t_builtin)(t_ms_data *data, char *arg);

typedef struct			s_builtin_e
{
	struct s_builtin_e	*next;
	t_builtin			fn;
	char				*name;
	size_t				len;
}						t_builtin_e;

t_builtin_e				*ms_builtins_init(void);
t_builtin_e				*ms_is_builtin(t_builtin_e *head, char *name);
char					*ms_extract_str(char *arg);

#endif