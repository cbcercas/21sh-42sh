/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:17:26 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/13 23:53:14 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DATA_H
# define DATA_H
# include <sys/param.h>
# include <environ/env_list_utils.h>
# include <logger/logger.h>

typedef struct s_sh_opt		t_sh_opt;
typedef struct s_sh_data	t_sh_data;

struct						s_sh_opt
{
	unsigned		verbose:1;
	unsigned		dbg:1;
	enum e_d_lvl	dbg_lvl;
};

struct						s_sh_data
{
	t_sh_opt			opts;
	char				*cwd;
	struct s_builtin_e	*builtins;
};

#endif