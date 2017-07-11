#include <expand/expand.h>

int     ft_strlen_before(const char *str)
{
    int     i;

    i = 0;
    while (str[i] && str[i] != '!')
        i++;
    return (i);
}

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

int     histisclear(const char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '!')
            return (0);
        i++;
    }
    return (1);
}

int    expand_hist_digit(t_exp *exp, int *i, int len)
{
    int     nb;
    int     size;
    char    *rep;

    nb = 0;
    rep = NULL;
    size = ft_numlen(&exp->str[*i + 1]);
    if((nb = ft_atoi(&exp->str[*i + 1])) != 0)
    {
        if((rep = (char *)sh_history_get_at(nb)) != NULL)
        {
            exp->str = ft_replace_exp(exp->str, rep, len, size + 1);
            *i += ft_strlen(rep);
            return (1);
        }
    }
    return (0);
}

void    expand_hist_alpha(t_exp *exp, int *i, int len)
{
    char *hist;
    int  nb;

    nb = ft_strlen(&exp->str[*i + 1]) + 1;
    hist = NULL;
    if ((hist = (char *)sh_history_get_search(&exp->str[*i + 1])) != NULL)
    {
        exp->str = ft_replace_exp(exp->str, hist, len, nb);
        *i += ft_strlen(hist);       
    }
}

















