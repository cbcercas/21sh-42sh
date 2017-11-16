/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_history_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expand/expand.h>

/*
** @brief Calculate the size of a string until a `!` is reached
**
** @param str The string to be measured
**
** @return Returns the lenght of str from begining to a `!`. If no ! is
** found, The result returned is the full lenght of str
*/

int     ft_strlen_before(const char *str)
{
    int     i;

    i = 0;
    while (str[i] && str[i] != '!')
        i++;
    return (i);
}

/*
** @brief Calculates the lenght of a number
** Example: `10` = 2 or `1970` = 4
**
** @param str The number in string form
**
** @return Returns the number's lenght
*/

int     ft_numlen(const char *str)
{
    int     i;

    i = 0;
    if (str[i] == '-')
        i++;
    while(ft_isdigit(str[i]))
        i++;
    return (i);
}

/*
** @brief TODO
** @param exp TODO
** @param i TODO
** @param len TODO
** @return TODO
*/

int    expand_hist_digit(t_exp *exp, int *i, int len)
{
    int     nb;
    int     size;
    char    *rep;

    nb = 0;
    rep = NULL;
    size = ft_numlen(&exp->str->s[*i + 1]);
    if((nb = ft_atoi(&exp->str->s[*i + 1])) != 0)
    {
        if((rep = (char *)sh_history_get_at(nb)) != NULL)
        {
            exp->str->s = ft_replace_exp(exp->str->s, rep, len, size + 1);
            *i += ft_strlen(rep);
            return (1);
        }
    }
    return (0);
}

/*
** @brief TODO
** @param exp TODO
** @param i TODO
** @param len TODO
** @return TODO
*/

int    expand_hist_alpha(t_exp *exp, int *i, int len)
{
    char *hist;
    int  nb;

    nb = ft_strlen(&exp->str->s[*i + 1]) + 1;
    hist = NULL;
    if ((hist = (char *)sh_history_get_search(&exp->str->s[*i + 1])) != NULL)
    {
        exp->str->s = ft_replace_exp(exp->str->s, hist, len, nb);
        *i += ft_strlen(hist);
        return (1);
    }
    return (0);
}