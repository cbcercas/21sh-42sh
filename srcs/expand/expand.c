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

t_return	expand(t_array *tokens, t_array *expand) {
	t_exp *exp;
	size_t i;

	i = 0;
	if (tokens->used == 0)
		return (E_RET_EXPAND_ERROR);
	while (i < tokens->used)
	{
		if (!(exp = exp_create_new((t_token *)array_get_at(tokens, i))))
			return (E_RET_EXPAND_ERROR);
		if (!expand_exp(exp))
			return (E_RET_EXPAND_ERROR);
		expand_remove_quote(exp);
		array_push(expand, (void *) exp);
		i++;
	}
	expand_merge_tokens_word(expand);
	return (E_RET_EXPAND_OK);
}