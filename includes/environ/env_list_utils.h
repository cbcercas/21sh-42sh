/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:27:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 09:47:14 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENV_LIST_UTILS_H
# define ENV_LIST_UTILS_H
# include "libft.h"

typedef struct	s_env
{
	struct s_env	*next;
	char			*name;
	char			*value;
}				t_env;

char	*cbc_getenv_name(char *env);
char	*cbc_getenv_value(char *env);
t_env	*cbc_new_env(char *env);

#endif