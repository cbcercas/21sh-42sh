/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:44:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 15:19:08 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <tools/tools.h>
# include <core/return.h>
# include <btree/ft_btree.h>
# include <array/array.h>
# include <logger.h>
# include <expand/expand.h>
# include <secure_memory/secure_memory.h>
# include <ftprintf.h>

/*
** @file ast.h
**
** @brief Function prototypes for the abstract syntax tree
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @struct s_info
**
** @brief  struct containing return value for exec.
*/

struct					s_info
{
	int					ret;
};

typedef struct s_info	t_info;

/*
** @struct s_cmd
**
** @brief node of the AST tree
**
** @param  av    a char tab for execve containing the args for the cmd executed
** @param  type  a type for process exec
** @param  info  struct info
*/

struct					s_cmd
{
	char				**av;
	t_token_type		type;
	t_info				info;
};

typedef struct s_cmd	t_cmd;

/*
** @struct s_lim
**
** @brief virtual limit for ast_built/ast_built2
*/

struct					s_lim
{
	ssize_t				cnt;
	ssize_t				lim;
};

typedef struct s_lim	t_lim;

/*
** @file       ast.c
**
** @brief      Main functions of the ast
*/

t_return				ast_create(t_btree **ast, t_array *tokens);

/*
** @file       ast_built.c
**
** @brief      Contains functions used to build the ast
*/

t_btree					*ast_built(t_btree **ast, t_array *expands, t_lim lim,
									int prio);

/*
** @file       ast_cmp.c
**
** @brief      Functions to compare the ast nodes to one another
*/

t_token_type			return_type(int prio, t_token_type type, \
                                    t_array *expands, ssize_t cnt);
BOOL					ast_prio(t_token_type type, int prio, ssize_t cnt, \
                                t_array *expands);
int						ast_cmp(t_cmd *s1, t_cmd *s2);

/*
** @file       ast_is_redir.c
**
** @brief      Functions to test ast nodes return types
*/

t_token_type			ast_return_type_redir(t_array *expands, \
                                            ssize_t cnt, t_token_type type);
BOOL					ast_is_redir(t_array *expands, ssize_t cnt, \
                                    t_token_type type);

/*
** @file       ast_utils.c
**
** @brief      Utility functions for the ast module
*/

void					ast_del_cmd(t_cmd *cmd);
char					*ast_aff(t_cmd *cmd);
t_exp					*ast_search(t_array *expands, t_lim *lim, int prio);
t_cmd					*ast_new_cmd(t_array *expands, ssize_t start, \
                                    ssize_t end, t_token_type type);
t_lim		swap_lim(t_lim lim);
t_btree			*ast_built2(t_btree **ast, t_array *expands,
							   t_lim lim, int prio);
#endif
