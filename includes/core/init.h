/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/06 18:34:17 by gpouyat         ###   ########.fr       */
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
#include <tests/expand_tests.h>
# include <signals/signals.h>
# include <core/deinit.h>

# define NOTATTY 1

/**
 * @file       init.c
 *
 * @brief      Functions to init the program
 */

t_sh_data		*sh_init(t_sh_data *data, int ac, char *const *av, char **environ);
void sh_store_tattr(t_sh_data *data);

#endif
