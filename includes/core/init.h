/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 16:48:06 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INIT_H
# define INIT_H
# include <unistd.h>
# include <libft.h>
# include <ftprintf.h>
# include <environ/env_list_utils.h>
# include <environ/environ.h>
# include <builtins/builtins_utils.h>
# include <core/main.h>
# include <unistd/ft_unistd.h>
# include <core/help.h>
# include <core/data.h>

t_sh_data		*sh_init(t_sh_data *data, int ac, char *const *av);
void			sh_deinit(t_sh_data *data);

#endif