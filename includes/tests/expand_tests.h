/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 10:00:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/10 16:33:27 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_TESTS_H
# define AST_TESTS_H

# include <automaton/automaton.h>
# include <lexer/lexer.h>
# include <parser/parser.h>
# include <libft.h>
# include <expand/expand.h>
# include <history/history.h>

void sh_testing_expand(char *const *av, char **environ);

#endif
