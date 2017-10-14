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

# include <btree/ft_btree.h>
# include <types/bool.h>
# include <logger.h>
# include <libft.h>
# include <lexer/lexer.h>
# include <expand/expand.h>

/**
 * @struct s_info
 *
 * @brief  struct containing return value for exec.
 */
struct								s_info
{
	//int 								redir_fd_in;
	//int 								redir_fd_out;
	int 								ret;
};

typedef struct s_info	t_info;

/**
 * @struct s_cmd
 *
 * @brief  node for the AST tree
 *
 * @param  a char ** for execve
 * @param  a type for process exec
 * @param  struct info
 *
 */

struct 								s_cmd
{
	char								**av;
	t_token_type				type;
	t_info							info;
};

typedef struct s_cmd	t_cmd;


/**
 * @struct s_lim
 *
 * @brief virtual limit for ast_built/ast_built2
 */

struct 								s_lim
{
	size_t							cnt;
	size_t							lim;
};

typedef struct s_lim	t_lim;

/**
 * @file       ast.c
 *
 * @brief      Main functions for the ast
 */

t_btree								*ast_create(t_btree **ast, t_array *tokens);

/**
 * @file       ast_built.c
 *
 * @brief      Contains function used to build the ast
 */

t_btree								*ast_built(t_btree **ast, t_array *expands, t_lim lim,\
	 																int prio);

/**
 * @file       ast_cmp.c
 *
 * @brief      Functions to compare the ast nodes to one another
 */

t_token_type					return_type(int prio, t_token_type type,\
	 																	t_array *expands, size_t cnt);
BOOL									ast_prio(t_token_type type, int prio, size_t cnt,\
	 																t_array *expands);
int										ast_cmp(t_cmd *s1, t_cmd *s2);

/**
 * @file       ast_is_redir.c
 *
 * @brief      Functions to test ast nodes return types
 */

t_token_type					ast_return_type_redir(t_array *expands,\
	 																						size_t cnt, t_token_type type);
BOOL									ast_is_redir(t_array *expands, size_t cnt,\
	 																									t_token_type type);

/**
 * @file       ast_utils.c
 *
 * @brief      Utility functions for the ast module
 */

void									ast_del_cmd(t_cmd *cmd);
char									*ast_aff(t_cmd *cmd);
t_exp									*ast_search(t_array *expands, t_lim *lim, int prio);
t_cmd									*ast_new_cmd(t_array *expands, int start,\
	 																			int end, t_token_type type);
#endif
