/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:44:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/07 17:03:53 by gpouyat          ###   ########.fr       */
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
 * \struct t_info
 * \brief struct for exec.
 *
 */
struct								s_info
{
	//int 								redir_fd_in;
	//int 								redir_fd_out;
	int 								ret;
};

typedef struct s_info	t_info;

/**
 * \struct t_cmd
 * \brief node of the AST tree
 *
 * node of the tree
 * contains:
 * -a char ** for execve
 * -a type for process exec
 * -struct info
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
 * \struct t_lim
 * \brief virtual limit for ast_built/ast_built2
 *
 *
 */
struct 								s_lim
{
	size_t							cnt;
	size_t							lim;
};

typedef struct s_lim	t_lim;


t_btree								*ast_create(t_array *tokens);

t_btree								*ast_built(t_btree *ast, t_array *expands, t_lim lim,\
	 																int prio);

t_token_type					return_type(int prio, t_token_type type,\
	 																	t_array *expands, size_t cnt);
BOOL									ast_prio(t_token_type type, int prio, size_t cnt,\
	 																t_array *expands);
int										ast_cmp(t_cmd *s1, t_cmd *s2);

t_token_type					ast_return_type_redir(t_array *expands,\
	 																						size_t cnt, t_token_type type);
BOOL									ast_is_redir(t_array *expands, size_t cnt,\
	 																									t_token_type type);

void									ast_del_cmd(t_cmd *cmd);
char									*ast_aff(t_cmd *cmd);
t_exp									*ast_search(t_array *expands, t_lim *lim, int prio);
t_cmd									*ast_new_cmd(t_array *expands, int start,\
	 																			int end, t_token_type type);

# define ISSEP(x) (x == E_TOKEN_SEMI || x == E_TOKEN_AND_IF ||\
	 									x == E_TOKEN_OR_IF)
# define ISPIPE(x) (x == E_TOKEN_PIPE)
# define ISLGAND(x) (x == E_TOKEN_GREATAND || x == E_TOKEN_LESSAND)
# define ISRED(x) (x == E_TOKEN_LESSGREAT || x == E_TOKEN_DLESS ||\
	 										x == E_TOKEN_DGREAT || x == E_TOKEN_DGREAT || ISLGAND(x))

#endif
