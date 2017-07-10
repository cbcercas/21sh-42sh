#include <expand/expand.h>

t_exp    *expand_hist(t_exp *exp)
{
    size_t  nb;

    nb = 0;
    if (exp->str[0] == '!' && ft_isalnum(exp->str[1]))
    {
        if((nb = ft_atoi(&exp->str[1])) != 0)
            exp->str = ft_replace_exp(exp->str, (char *)sh_history_get_at(nb), 0, ft_strlen(exp->str));
        else
            exp->str = ft_replace_exp(exp->str, (char *)sh_history_get_search(&exp->str[1]), 0, ft_strlen(exp->str));
    }
    // ft_printf("%s\n", exp->str);
    // ft_expand_print_token(exp->type);
    return(exp);
}