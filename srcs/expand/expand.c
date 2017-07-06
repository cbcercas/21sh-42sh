#include <expand/expand.h>

void expand_print(t_array *array_exp)
{
  t_exp   *exp;
  size_t  i;

  i = 0;
  if (!array_exp || i >= array_exp->used)
    return ;
  ft_printf("-----Expand------\n");
  while (i < array_exp->used)
  {
    exp = (t_exp *)array_get_at(array_exp, i);
    if (exp)
      ft_printf("Exp[%zu] = {%s}\n", i, exp->str);
    i++;
  }
}


t_array *expand(t_array *tokens, t_array *array_exp)
{
  t_exp   *exp;
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
  return (array_exp);
}


/*void	test(t_array *toks)
{
    size_t	cnt;
    t_token	*tok;

    cnt = 0;
    while (cnt < toks->used)
    {
        tok = (t_token *)array_get_at(toks, cnt);
       	ft_printf("tok->str: {%s}\n", tok->str);
       	ft_printf("tok->len: %d\n", tok->len);
       	lexer_print_token(tok);
       	ft_putstr("\n\n");
        cnt++;
    }
}*/

/**
** @brief      Initialize the t_array for expended tokens
** @param      t_array*   the structure to initialize
** @return     t_array*   the structure initialized
*/

/*t_array *expand_create(void)
{
  static t_array  *e = NULL;

  if (e == NULL)
  {
    if ((e = array_create(sizeof(t_token))) == NULL)
    {
      log_fatal("Expand: can't initialise tokens_expended array");
      ft_dprintf(STDERR_FILENO, "Expand: can't initialise tokens_expended array");
      exit(1);
    }
  }
  return (e);
}


t_array *expand_init(t_array **tokens_expended)
{
  if ((*tokens_expended = expand_create()) != NULL)
  {
    log_info("Expand: Initialization done");
    return (*tokens_expended);
  }
  log_fatal("Expand: Initialization failed");
  return (NULL);
}


t_array *expand_exp(t_array *tokens, t_array **tokens_expended)
{
    size_t  cnt;
    t_token *tok;

    cnt = 0;
    while (cnt < tokens->used)
    {
        // tok = ft_memalloc(sizeof(t_token));
        tok = (t_token *)array_get_at(tokens, cnt);
        array_push(*tokens_expended, (void *)tok);

        cnt++;
    }
    return (*tokens_expended);
}*/
