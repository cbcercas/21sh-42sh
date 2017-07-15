#include <expand/expand.h>

void 	expand_merge_tokens_word(t_array *array_exp)
{
	t_exp 	*tmp1;
	t_exp 	*tmp2;
	size_t 	i;

	i = 0;
	tmp1 = NULL;
	tmp2 = NULL;
	while (array_exp && (i + 1 < array_exp->used))
	{
		tmp1 = (t_exp *)array_get_at(array_exp, i);
		if (tmp1->type == E_TOKEN_WORD)
		{
			tmp2 = (t_exp *)array_get_at(array_exp, i + 1);
			if (tmp2->type == E_TOKEN_WORD)
			{
				string_insert_back(tmp1->str, tmp2->str->s);
				string_del(&tmp2->str);
				array_remove_at(array_exp, i + 1, NULL);
				ft_printf("tmp1= %s\n", tmp1->str->s);
			}
		}
		i++;
	}
}