/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/15 13:30:01 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INIT_H
# define INIT_H
# include <unistd.h>
# include <libft.h>
# include <ft_printf/libftprintf.h>
# include <environ/env_list_utils.h>
# include <environ/environ.h>
# include <builtins/builtins_utils.h>
# include <core/main.h>

t_ms_data		*ms_init(void);
void		ms_deinit(t_ms_data **data);

#endif