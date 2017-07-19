/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:06:22 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/19 17:47:31 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PATH_H
#define CHECK_PATH_H

# include <libft.h>
# include <ftprintf.h>
# include <environ/env_list_utils.h>
# include <environ/environ.h>

#include <sys/stat.h>

char	*sh_check_path(char const *cmd_name);
char *get_filename(char *av);

#endif
