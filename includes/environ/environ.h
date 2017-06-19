/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:43:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 19:08:04 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H
# include <environ/env_list_utils.h>
# include <environ/builtin_env.h>
# include <environ/builtin_env_utils.h>
# include <environ/getter_env.h>
# include <environ/modif_env.h>
# include <logger.h>

t_array	*sh_init_environ(void);
char	**sh_tenv_to_tab(void);


#endif