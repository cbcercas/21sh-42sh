/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:27:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 16:49:24 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENV_LIST_UTILS_H
# define ENV_LIST_UTILS_H
# include <libft.h>
# include <logger.h>
# include <ftprintf.h>

typedef struct	s_env
{
	struct s_env	*next;
	char			*name;
	char			*value;
}				t_env;

char	*split_env_name(char const *env);
char	*split_env_value(char const *env);
t_env	*env_new(char *name, char *value);
void	del_env(t_env **e);
void	sh_lst_env_del(t_env **head);

#endif