#include <expand/expand.h>

t_exp    *expand_hist(t_exp *exp)
{
  //si jai un token ! et un token number ==> j'utilise sh_history_get_at
  if (exp->str[0] == '!' ) // and if next token is a number
  {
    if ((exp->str = ft_replace_exp(exp->str, (char *)sh_history_get_at(5), 0, ft_strlen(exp->str))) == NULL)
    {
      log_fatal("Expand: ft_replace_exp failed");
      return (NULL);
    }
  }
  //si jai un token ! et un token word ==> j'utilise sh_history_get_search
  ft_printf("%s\n", exp->str);
  ft_expand_print_token(exp->type);
  return(exp);
}