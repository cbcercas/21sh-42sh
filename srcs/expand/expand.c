#include <expand/expand.h>

t_array    *ft_expand_duplication(t_exp *exp, t_array *tokens, t_array *array_exp)
{
  size_t  i;

  i = 0;
  if (!tokens || !array_exp || i >= tokens->used)
    return (NULL);
  while (tokens && i < tokens->used)// dans tous les tokens
  {
    exp = exp_create_new((t_token *)array_get_at(tokens, i));// etape 1
    array_push(array_exp, (void *)exp);// push dans notre t_array
    i++;
  }
  return(array_exp);
}

t_array    *ft_expand_history(t_array *array_exp, size_t index)
{
  t_exp   *exp;

  if ((exp = (t_exp *)array_get_at(array_exp, index)) == NULL)
    return (NULL);
  // exp->str = ft_replace_exp(exp->str, (char *)sh_history_get_at(2), 0, ft_strlen(exp->str));
  ft_printf("%s\n", exp->str);
  ft_expand_print_token(exp->type);
  return(array_exp);
}


t_array *expand(t_array *tokens, t_array *array_exp)
{
  t_exp   *exp;

  /*step 1: tokens duplication for next steps*/
  if (ft_expand_duplication(exp, tokens, array_exp) == NULL)
    return (NULL);
  /*step 2: ft_replace "!"*/
  if (ft_expand_history(array_exp, 0) == NULL)
    return (NULL);
  /*step 3: ft_replace "$"*/
  /*step 4: remove "/", "" and ''*/
  /*step 5: loop on each token step 2, 3, 4*/
  return (array_exp);
}