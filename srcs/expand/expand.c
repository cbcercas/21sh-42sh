#include <expand/expand.h>


void	test(t_array *toks)
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
}

/**
** @brief      Initialize the t_array for expended tokens
** @param      t_array*   the structure to initialize
** @return     t_array*   the structure initialized
*/

t_array *expand_init(t_array *tokens_expended)
{
  tokens_expended = array_init(tokens_expended, sizeof(t_token));
  if (tokens_expended != NULL)
  {
    log_info("Expand: Initialization done");
    printf("Expand: Initialization done\n");
    return (tokens_expended);
  }
  printf("Expand: Initialization failed\n");
  log_fatal("Expand: Initialization failed");
  return (NULL);
}


t_array *expand_exp(t_array *tokens, t_array *tokens_expended)
{
    size_t  cnt;
    t_token *tok;

    cnt = 0;
    while (cnt < tokens->used)
    {
        tok = (t_token *)array_get_at(tokens, cnt);
        array_push(tokens_expended, (t_token *)tok);
        cnt++;
    }
    return (tokens_expended);
}