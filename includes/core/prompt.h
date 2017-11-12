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

# include "input.h"
# include "return.h"

void sh_print_prompt(t_input *input, const char *prompt, t_return ret);
size_t	sh_len_prompt(void);


#endif
