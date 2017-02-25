/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:27:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 16:39:51 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENV_LIST_UTILS_H
# define ENV_LIST_UTILS_H
# include <libft.h>

typedef struct	s_env
{
	struct s_env	*next;
	char			*name;
	char			*value;
}				t_env;

char	*ms_getenv_name(char const *env);
char	*ms_getenv_value(char const *env);
t_env	*ms_new_env(char *name, char *value);
void	ms_env_del(t_env **e);
void	ms_lst_env_del(t_env **head);

#endif