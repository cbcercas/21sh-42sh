/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:43:08 by gpouyat           #+#    #+#             */
/*   Updated: 2017/08/01 10:31:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief Initializes the expand and its array
**
** @param expand_array The t_array containing the expand to be initialized
**
** @return Returns the initialized t_array if successful, NULL otherwise
*/

t_array		*expand_init(t_array *expand_array)
{
	expand_array = array_init(expand_array, sizeof(t_exp));
	if (expand_array)
	{
		log_info("Expand: Initialization done");
		return (expand_array);
	}
	log_fatal("Expand: Initialization failed");
	ft_dprintf(2, "Expand: Initialization failed");
	return (NULL);
}

/*
** @brief Creates a new token with the same t_string
**
** @param tok Token source
**
** @return Returns the new token
*/

t_exp		*exp_create_new(t_token *tok)
{
	t_exp	*exp;

	if (!tok || !tok->str || !(exp = (t_exp*)ft_secu_malloc_lvl(sizeof(t_exp),
																M_LVL_EXPA)))
		return (NULL);
	exp->type = tok->type;
	exp->str = string_ndup(tok->str, tok->len);
	return (exp);
}

/*
** @brief Deletes a part of the expand
** @param i Part to be deleted
*/

void		sh_exp_del(void *i)
{
	t_exp *exp;

	exp = (t_exp *)i;
	if (exp && exp->str)
		string_del(&(exp->str));
}

/*
** @brief Destroys the expand
** @param array_exp array containing the expand to be destroyed
*/

void		sh_expand_destroy(t_array *array_exp)
{
	if (array_exp)
		array_destroy(&array_exp, sh_exp_del);
}
