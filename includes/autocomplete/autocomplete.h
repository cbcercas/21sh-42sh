/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:51 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/18 16:39:01 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include <stddef.h>
# include <libft.h>
# include <ftprintf.h>
# include <logger.h>

char *autoc_get_last_word(char *current_input);
void    autoc_add_to_array(char *to_add, t_array *array);
char	*autoc_get_from_array_at(size_t pos, t_array *array);
void autoc_array_print(t_array *array);
t_array *autoc_get_dir_content(char *path);

#endif
