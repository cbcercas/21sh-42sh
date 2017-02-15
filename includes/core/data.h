/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:17:26 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/13 23:53:14 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DATA_H
# define DATA_H
# include <environ/env_list_utils.h>

typedef struct	s_ms_data
{
	t_env				*env;
	char				*cwd;
	struct s_builtin_e	*builtins;
}				t_ms_data;

#endif