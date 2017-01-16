/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 11:18:52 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INIT_H
# define INIT_H
# include <unistd.h>
# include "libft.h"
# include "libftprintf.h"
# include "env_list_utils.h"
# include "environ.h"

typedef struct	s_main_data
{
	t_env	*env;
	char	*cwd;
}				t_main_data;

t_main_data		*init(void);
#endif