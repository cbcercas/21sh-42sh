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

char *autoc_get_last_word(char *current_input);
char **autoc_get_possibilities(char *word);

#endif
