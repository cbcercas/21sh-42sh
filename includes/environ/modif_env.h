/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIF_ENV_H
# define MODIF_ENV_H

# include <array/array.h>
# include "env_list_utils.h"

t_env	*del_var(t_array *vars, char const *name);
t_env	*set_var(t_array *vars, char const *name,
				char const *value, BOOL is_export);

#endif
