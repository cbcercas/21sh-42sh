/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:35 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/24 21:05:40 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <unistd.h>
# include <core/init.h>
# include <core/parsing_command.h>
# include <core/data.h>
# include <core/check_path.h>

int	ms_command(t_ms_data *data, t_command *command);
char **ms_get_command(char *input);
int	ms_exec_command(char **command, const t_env *env);

#endif