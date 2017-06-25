/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:44:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/25 18:42:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <btree/ft_btree.h>
# include <types/bool.h>
# include <logger.h>
# include <libft.h>
# include <lexer/lexer.h>

typedef struct s_info	t_info;

struct	s_info
{
	int redir_fd_in;
	int redir_fd_out;
	int ret;
};

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char const			*str;
	t_info					info;
	t_token_type		type;
};

typedef struct s_lim	t_lim;

struct s_lim
{
	size_t	cnt;
	size_t	lim;
};

t_btree	*ast_create(t_array *tokens);
t_btree	*ast_built1(t_btree *ast, t_array *tokens, t_lim lim);
t_btree	*ast_built2(t_btree *ast, t_array *tokens, t_lim lim);
t_btree	*ast_built3(t_btree *ast, t_array *tokens, t_lim lim);
t_btree	*ast_built4(t_btree *ast, t_array *tokens, t_lim lim);
t_btree	*ast_built6(t_btree *ast, t_array *tokens, t_lim lim);

BOOL	ast_is_redir(t_array *tokens, size_t cnt, t_token *cur);
t_btree	*ast_built_greatand(t_btree *ast, t_array *tokens, t_lim lim);

void	ast_del_cmd(t_cmd *cmd); //TODO: refactor quand expand sera fini
char	*ast_aff(t_cmd *cmd);//TODO: refactor quand expand sera fini
int	ast_cmp(t_cmd *s1, t_cmd *s2);//TODO: refactor quand expand sera fini
t_cmd	*ast_new_cmd(const char *str, size_t len, t_token_type type);//TODO: refactor quand expand sera fini

#endif
