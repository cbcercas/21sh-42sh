/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_local_var.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_LOCAL_VAR_H
# define BUILTIN_LOCAL_VAR_H

# include <core/data.h>
# include <ftprintf.h>
# include <environ/env_utils.h>
# include <environ/modif_env.h>
# include <stdio.h>
# include <unistd/ft_unistd.h>
# include <environ/getter_env.h>

int	builtin_unset(t_sh_data *data, char **argv);
int	builtin_export(t_sh_data *data, char **argv);

#endif