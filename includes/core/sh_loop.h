/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:30:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 08:31:13 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LOOP_H
# define SH_LOOP_H

# include <libft.h>
# include <btree/ft_btree.h>
# include <core/main.h>
# include <exec/exec.h>
# include <history/history.h>
# include <parser/parser.h>
# include <core/sh_get_input.h>
# include <secure_memory/secure_memory.h>
# include <core/progname.h>

/*
** @file   sh_loop.h
**
** @brief  Function prototypes for the main loop
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file sh_loop.c
**
** @brief The main loop for the program
*/

void			sh_arrays_reset(t_array *tokens, t_array *expands);
BOOL			sh_loop(t_sh_data data, struct s_exec_data *exec_dat,
						t_return *ret);

#endif
