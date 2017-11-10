#include <core/tcaps.h>
#include <core/input.h>
#include <history/history.h>


static void	exec_alt_v_multi(t_input *input, char *save)
{
	char	*tmp;
	t_input		*next_save;
	size_t		len;

	len = 0;
	get_select()->str = ft_strjoincl(get_select()->str,
									 &input->str->s[pos_in_str(input)], 0);
	string_remove(input->str, pos_in_str(input), input->str->len);
	while (get_select()->str[len] && get_select()->str[len] != '\\')
		len ++;
	string_insert_back(input->str, tmp = ft_strsub(get_select()->str, 0, len));
	ft_strdel(&tmp);
	tmp = get_select()->str;
	get_select()->str = ft_strchr(get_select()->str, '\n') + 1;
	next_save = input->next;
	input->next = input_from_history(get_select()->str);
	if (next_save)
		next_save->prev = input_get_last(input);
	if (input->next)
		input->next->prev = input;
	input_get_last(input)-> next = next_save;
	redraw_input(input);
	ft_strdel(&tmp);
	get_select()->str = save;
	get_windows(0)->cur = input;
}

BOOL	exec_alt_v(const t_key *key, t_input *input)
{
	char	*save;

	(void)key;
	if (get_select()->is || !input || !input->str || !get_select()->str)
		return (false);
	save = get_select()->str;
	if (ft_strchr(get_select()->str, '\\'))
	{
		log_dbg3("copy multi");
		exec_alt_v_multi(input, save);
	}
	else
	{
		log_dbg3("copy simple");
		string_insert(input->str, get_select()->str, pos_in_str(input));
		redraw_input(input);
		return (false);
	}
	return (false);
}
