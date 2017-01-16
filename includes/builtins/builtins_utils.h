/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 15:27:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUILTINS_UTILS_H
# define BUILTINS_UTILS_H
#include "exit.h"

typedef 	int (**t_builtins)(char **arg);
typedef 	int (*t_builtin)(char **arg);

enum		builtins{
	ems_exit,
	last
};

t_builtins	ms_builtins_init(void);

#endif