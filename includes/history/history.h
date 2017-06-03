/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:56:40 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/03 16:47:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <logger.h>
# include <libft.h>
# include <gnl/get_next_line.h>
# include <ftprintf.h>
# include <history/history_list_utils.h>

t_array		*sh_history_get(void);
int 			sh_history_open_fd(void);
t_array		*sh_history_init(void);
void 			sh_history_print();

#endif
