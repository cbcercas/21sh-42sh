/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/15 18:04:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "data.h"

# define NOTATTY 1

/*
** @file       init.c
**
** @brief      Functions to init the program
*/

t_sh_data		*sh_init(t_sh_data *data, int ac, char *const *av,
						char **environ);
void			sh_store_tattr(t_sh_data *data);
void			sh_check_env(char **environ);
void			sh_options(t_sh_opt *opts, int ac, char *const *av,
						char **environ);
void			sh_testing(const char *arg, char *const *av, char **environ);

#endif
