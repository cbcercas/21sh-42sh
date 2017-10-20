/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:06:22 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/09 18:35:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PATH_H
#define CHECK_PATH_H

char	*sh_check_path(char const *cmd_name);
char *get_filename(char *av);
char		*makefilepath(char const *path, char const *filename);

#endif
