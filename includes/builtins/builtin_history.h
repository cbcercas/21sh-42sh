/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:54:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 19:15:01 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_HISTORY_H
#define BUILTIN_HISTORY_H

# include <history/history.h>
# include <core/data.h>


int		sh_history(t_sh_data *data, char **arg);
void	sh_history_builtin_a(char *str);
void	sh_history_builtin_print(const char *arg);
void	sh_history_builtin_print2(int nb);
void	sh_history_builtin_c(void);
void	sh_history_builtin_d(const char *arg);
void	sh_history_builtin_w(char *path);
void	sh_history_builtin_s(char **argv, int index);
void	sh_history_builtin_r(char *path);
void sh_history_builtin_n(char *path);
void	sh_history_builtin_p(char **arg);

#endif
