/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:49:31 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/12 11:21:31 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include <ftprintf.h>
# include <core/data.h>
# include <builtins/builtin_history.h>
# include <core/tcaps.h>
# include <core/init.h>

/**
 * @file   builtin_exit.c
 *
 * @brief  Contains the functions for the exit builtin
 */

int	sh_exit(t_sh_data *data, char **arg);

#endif
