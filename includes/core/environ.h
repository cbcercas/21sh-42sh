/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:43:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 09:42:56 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H
# include "env_list_utils.h"

typedef struct	s_env
{
	struct s_env	*next;
	char			*name;
	char			*value;
}				t_env;

t_env	*cbc_copy_environ(void);

#endif