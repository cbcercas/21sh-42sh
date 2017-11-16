/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <expand/expand.h>

/*
** @brief Expands the history
** @param exp TODO
** @return TODO
*/

t_exp   *expand_hist(t_exp *exp)
{
    int i;
    int len;
    char    *rep;

    i = 0;
    len = 0;
    rep = NULL;
    while (exp->str->s[i])
    {
        len = ft_strlen_before(exp->str->s);
        if (exp->str->s[i] == '\\')
            i += 2;
        else if (exp->str->s[i] == '!' && exp->str->s[i + 1] == '!')
        {
            if((rep = (char *)sh_history_get_at(-1)) != NULL)
                exp->str->s = ft_replace_exp(exp->str->s, rep, len, 2);
            i += ft_strlen(rep);
        }
        else if (exp->str->s[i] == '!' && (ft_atoi(&exp->str->s[i + 1]) != 0))
        {
            if (expand_hist_digit(exp, &i, len) == 0)
                return (NULL);
        }
        else if (exp->str->s[i] == '!' && ft_isalpha(exp->str->s[i + 1]))
        {
            if (expand_hist_alpha(exp, &i, len) == 0)
                return (NULL);
        }
        else
            i++;
    }
    return(exp);
}