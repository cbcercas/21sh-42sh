/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:27:56 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/29 23:31:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

void	sh_print_prompt(void);
size_t sh_len_prompt(void);
# include "input.h"

int g_ret;

#endif
