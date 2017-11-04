#include <expand/expand.h>

t_exp *expand_exp(t_exp *exp)
{
  if (exp->type == E_TOKEN_WORD || exp->type == E_TOKEN_DQUOTE)
  {
    expand_dol(exp->str);
    if (expand_hist(exp) == NULL)
    {
      ft_printf("event not found\n");
      return (NULL);
    }
  }
  return (exp);
}

t_array *expand(t_array *tokens, t_array *array_exp)
{
  t_exp   *exp;
  size_t  i;

  i = 0;
  if (!tokens || !array_exp || i >= tokens->used)
    return (NULL);
  while (tokens && i < tokens->used)
  {
    if (!(exp = exp_create_new((t_token *)array_get_at(tokens, i))))
      return (NULL);
    if (!expand_exp(exp))
      return (NULL);
    expand_remove_quote(exp);
    array_push(array_exp, (void *)exp);
    i++;
  }
  expand_merge_tokens_word(array_exp);
  return(array_exp);
}