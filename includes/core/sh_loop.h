/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:30:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/10 13:30:44 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LOOP_H
# define SH_LOOP_H

#include <libft.h>
#include <btree/ft_btree.h>
#include <core/main.h>
#include <exec/exec.h>
#include <history/history.h>
#include <parser/parser.h>
#include <core/sh_get_line.h>
#include <ft_secu_malloc/ft_secu_malloc.h>
#include <core/progname.h>


void			sh_arrays_reset(t_array *tokens, t_array *expands);
BOOL		sh_loop(t_sh_data data, struct s_exec_data *exec_dat, t_return *ret);


#endif
