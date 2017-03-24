/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:06:22 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 16:32:11 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECK_PATH_H
#define CHECK_PATH_H

# include <libft.h>
# include <ft_printf/libftprintf.h>
# include <environ/env_list_utils.h>
# include <environ/environ.h>

#include <sys/stat.h>

char	*sh_check_path(char const *cmd_name, t_env const *env);

#endif