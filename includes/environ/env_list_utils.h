/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 09:27:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/15 18:23:48 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_UTILS_H
# define ENV_LIST_UTILS_H

# include <libft.h>

/*
** @file   env_list_utils.h
**
** @brief  Function prototypes for the env utility things
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @brief TODO
** @arg TODO
*/

typedef struct		s_env
{
	struct s_env	*next;
	char			*name;
	char			*value;
	BOOL			is_export;
}					t_env;

/*
** @file   env_list_utils.c
**
** @brief  Utility functions for the env
*/

char				*split_var_name(char const *env);
char				*split_var_value(char const *env);
t_env				*var_new(char *name, char *value, BOOL is_export);
void				del_env(void *e);
void				sh_lst_env_del(t_env **head);

#endif
