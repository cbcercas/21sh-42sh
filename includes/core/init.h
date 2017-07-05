/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/08 08:18:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INIT_H

# define INIT_H
# include <unistd.h>
# include <libft.h>
# include <ftprintf.h>
# include <environ/env_list_utils.h>
# include <environ/environ.h>
# include <builtins/builtins_utils.h>
# include <core/main.h>
# include <unistd/ft_unistd.h>
# include <core/help.h>
# include <core/data.h>
# include <tests/test.h>
# include <tests/lexer_tests.h>
# include <tests/parser_tests.h>
# include <signals/signals.h>

t_sh_data		*sh_init(t_sh_data *data, int ac, char *const *av, char **environ);
void			sh_deinit(t_sh_data *data);
struct termios    *init_term(void);
void reset_term(struct termios *tattr);


#endif
