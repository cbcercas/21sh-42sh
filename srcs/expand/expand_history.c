#include <expand/expand.h>

t_exp   *expand_hist(t_exp *exp)
{
    int i;
    int len;
    char    *rep;

    i = 0;
    len = 0;
    rep = NULL;
    while (exp->str[i])
    {
        len = ft_strlen_before(exp->str);
        if (exp->str[i] == '!' && exp->str[i + 1] == '!')
        {
            if((rep = (char *)sh_history_get_at(-1)) != NULL)
                exp->str = ft_replace_exp(exp->str, rep, len, 2);
        }
        else if (exp->str[i] == '!' && (ft_atoi(&exp->str[i + 1]) != 0))
        {
            if (expand_hist_digit(exp, i, len) == 0)
                break;
        }
        else if (exp->str[i] == '!' && histisclear(&exp->str[i + 1]))
        {
            expand_hist_alpha(exp, i, len);
        }
        else if (exp->str[i] == '!' && !(histisclear(&exp->str[i + 1])))
            break;
        i++;
    }
    return(exp);
}