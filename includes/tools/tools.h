/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:00:38 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/31 18:42:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <libft.h>
# include <ftprintf.h>
# include <btree/ft_btree.h>

void	ft_strdblfree(char **strdb);
BOOL  is_printstr(char const *line);
pid_t  sh_fork(void);
int    sh_pipe(int tube[2]);
int    sh_open_exec(t_btree *ast);
int    sh_open(char *file, int flags);
BOOL  ft_isdigit_str(char *str);

#endif
