/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:51 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/04 13:37:02 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include <core/progname.h>
# include <dirent.h>
# include <types/bool.h>
# include <logger.h>
# include <libft.h>
# include <ftprintf.h>
# include <core/input.h>
# include <ft_secu_malloc/ft_secu_malloc.h>
# include <history/history.h>

int     nb_of_word(char *s);
char    *find_word_after(t_input *input);
char    *find_word_cur(t_input *input);
int     get_nb_word_cur(t_input *input);
size_t  get_index_cur(t_input *input);
BOOL    autocomplete_is_command(t_input *input);
BOOL    autocomplete_is_path(t_input *input);
t_array *autocomplete_get_content_paths(char *path);
t_input *autocomplete(t_array *content, t_input *input);
void    autocomplete_display(t_array *content);
t_array *autocomplete_get_bin(char *begin);
BOOL    autocomplete_is_directory(char *path);
char    *autocomplete_get_path(char *s);
int		autocomplete_strnequ(char const *s1, char const *s2, size_t n);
void	autocomplete_display_prompt(t_input *input);

#endif
