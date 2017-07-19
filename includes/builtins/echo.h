/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:25 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/19 21:24:57 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H
# include <libft.h>
# include <ftprintf.h>
# include <core/data.h>
# include <exec/exec.h>
# include <builtins/builtins_utils.h>

/*typedef struct s_echo
{
	char			cur_q;
	int				lvl;
}				t_echo;*/

int	sh_echo(t_sh_data *data, char **arg);
extern int g_optind;

#endif
