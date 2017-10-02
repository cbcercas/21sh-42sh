/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/09/14 14:55:17 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

t_cmd *init_exec(t_btree *ast)
{
  if (!ast)
    return (NULL);
  return ((t_cmd *)ast->item);
}

/*
** @brief         handle ast before exec
**                it is recurcive function
**                fisrt is ast->left (branch left of binary tree AST)
**                if it is WORD so execute "normal"
**                if OR it is: "normal" OR "normal"
**                etc
**
** @param  data    The data of shell
** @param  ast     The AST (Analyse Syntax Tree[binary])
**
** @return     -1 on error or unknow TOKEN
*/

int   sh_process_exec(t_sh_data *data, t_btree *ast)
{
  t_cmd *item;

  if(!(item = init_exec(ast)))
    return (-1);
  if (item->type == E_TOKEN_WORD)
    return (sh_exec_simple(data, item));
  else if (item->type == E_TOKEN_PIPE)
		return (sh_process_pipe(data, ast));
  else if(item->type == E_TOKEN_AND_IF)
    return((sh_process_exec(data, ast->left) == 0) &&\
            (sh_process_exec(data, ast->right) == 0));
	else if(item->type == E_TOKEN_OR_IF)
	  return((sh_process_exec(data, ast->left) == 0) ||\
          (sh_process_exec(data, ast->right) == 0));
	else if(item->type == E_TOKEN_SEMI)
	{
		sh_process_exec(data, ast->left);
		return (sh_process_exec(data, ast->right));
	}
	else if((item->type == E_TOKEN_LESSGREAT) || (item->type == E_TOKEN_DLESS ) ||\
	 			(item->type == E_TOKEN_DGREAT))
      return(sh_exec_redir(data, ast, item));
  else if(item->type == E_TOKEN_GREATAND)
    return(sh_exec_greatand(data, ast, item));
  return (-1);
}
