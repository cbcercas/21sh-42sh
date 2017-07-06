/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 10:00:29 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/06 18:36:36 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_TESTS_H
# define AST_TESTS_H

# include <automaton/automaton.h>
# include <lexer/lexer.h>
# include <parser/parser.h>
# include <libft.h>
# include <expand/expand.h>

void sh_testing_expand(char *const *av);

#endif
