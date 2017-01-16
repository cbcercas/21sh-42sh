/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 11:51:34 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INIT_H
# define INIT_H
# include <unistd.h>
# include "libft.h"
# include "libftprintf.h"
# include "env_list_utils.h"
# include "environ.h"

typedef struct	s_ms_data
{
	t_env	*env;
	char	*cwd;
}				t_ms_data;

t_ms_data		*ms_init(void);
void		ms_deinit(t_ms_data **data);

#endif