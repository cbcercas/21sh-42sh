#include <expand/expand.h>

t_exp   *expand_hist(t_exp *exp)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (exp->str[i])
    {
        len = ft_strlen_before(exp->str);
        if (exp->str[i] == '!' && ft_isdigit(exp->str[i + 1]))
            expand_hist_digit(exp, i, len);
        else if (exp->str[i] == '!' && histisclear(&exp->str[i + 1]))
            expand_hist_alpha(exp, i, len);
        else if (exp->str[i] == '!' && !(histisclear(&exp->str[i + 1])))
            break;
        i++;
    }
    return(exp);
}