/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:34:02 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 16:47:09 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHDIR_H
# define CHDIR_H

# include <core/data.h>

/**
 * @file   builtin_chdir.c
 *
 * @brief  Contains the functions for chdir (cd)
 */

int		sh_chdir(t_sh_data *data, char **arg);
char	*expand_path(char **path);

#endif