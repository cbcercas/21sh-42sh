/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:31:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/21 13:03:18 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <array/array.h>
#include <btree/ft_btree.h>
//typedef struct s_array	t_array;

struct s_exec_data
{
	t_array		tokens;
	t_array		expand;
	t_btree		*ast;

};

#endif
