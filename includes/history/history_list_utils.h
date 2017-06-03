/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_list_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:01:33 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/03 16:42:38 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_LIST_UTILS_H
# define HISTORY_LIST_UTILS_H

# include <logger.h>
# include <libft.h>
# include <ftprintf.h>

typedef	struct	s_hist
{
	char					*cmd;
	char					*buf;
	size_t				*cur;
	struct s_hist	*next;
}								t_hist;

t_hist					*sh_history_new(char *cmd);

#endif
