#include <lexer/lexer.h>
#include <core/main.h>

t_array *expand_exp(t_array *tokens, t_array **tokens_expended);
t_array	*expand_init(t_array **tokens_expended);

void	test(t_array *toks);
