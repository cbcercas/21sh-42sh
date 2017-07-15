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
    {
      ft_printf("Exp[%zu] = {%s} ==>", i, exp->str.s);
      ft_expand_print_token(exp->type);
    }
    i++;
  }
}

void       ft_expand_print_token(t_token_type type)
{
  if (type == E_TOKEN_BLANK)
    ft_putstr("TOKEN_TYPE_BLANK");
  else if (type == E_TOKEN_NEWLINE)
    ft_putstr("TOKEN_TYPE_NEWLINE");
  else if (type == E_TOKEN_WORD)
    ft_putstr("TOKEN_TYPE_WORD");
  else if (type == E_TOKEN_SQUOTE)
    ft_putstr("TOKEN_TYPE_SQUOTE");
  else if (type == E_CHAR_TYPE_BQUOTE)
    ft_putstr("TOKEN_TYPE_BQUOTE");
  else if (type == E_TOKEN_DQUOTE)
    ft_putstr("TOKEN_TYPE_DQUOTE");
  else if (type == E_TOKEN_PIPE)
    ft_putstr("TOKEN_TYPE_PIPE");
  else if (type == E_TOKEN_OR_IF)
    ft_putstr("TOKEN_TYPE_OR_IF");
  else if (type == E_TOKEN_LESSGREAT)
    ft_putstr("TOKEN_TYPE_LESSGREAT");
  else if (type == E_TOKEN_DGREAT)
    ft_putstr("TOKEN_TYPE_DGREAT");
  else if (type == E_TOKEN_DLESS)
    ft_putstr("TOKEN_TYPE_DLESS");
  else if (type == E_TOKEN_AND)
    ft_putstr("TOKEN_TYPE_AND");
  else if (type == E_TOKEN_AND_IF)
    ft_putstr("TOKEN_TYPE_AND_IF");
  else if (type == E_TOKEN_SEMI)
    ft_putstr("TOKEN_TYPE_SEMI");
  else if (type == E_TOKEN_LESSAND)
    ft_putstr("TOKEN_TYPE_LESSAND");
  else if (type == E_TOKEN_GREATAND)
    ft_putstr("TOKEN_TYPE_GREATAND");
  else if (type == E_TOKEN_IO_NUMBER)
    ft_putstr("TOKEN_TYPE_IO_NUMBER");
  ft_putchar(10);
}