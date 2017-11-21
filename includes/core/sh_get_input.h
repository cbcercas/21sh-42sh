/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_input.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:30:24 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/21 08:30:56 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_GET_INPUT_H
# define SH_GET_INPUT_H

/*
** @file   sh_get_input.h
**
** @brief  Function prototypes to get the input
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file sh_get_input.c
**
** @brief Gets the input
*/

char		*sh_get_input(t_sh_data *data, char *prompt, t_return ret);

#endif
