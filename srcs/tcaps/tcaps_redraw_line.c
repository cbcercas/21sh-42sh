#include <core/tcaps.h>

void	redraw_line(t_input *input)
{
	char	*tmp;
	int		len;
	int		line;
	int		col;

	line = 0;
	col = 0;
	if (input->str->len == 0)
		return ;
	tmp = input->str->s + ((((input->cpos.cp_col + 1) - (input->offset_col + 1))
							+ (input->ts->ws_col * input->cpos.cp_line)));
	len = (int)ft_strlen(tmp);
	tputs(tmp, len, &ft_putchar2);
	if (len > (input->ts->ws_col - input->cpos.cp_col))
		line = (len - (input->ts->ws_col - input->cpos.cp_col))
						/ input->ts->ws_col + ((len - (input->ts->ws_col
							- input->cpos.cp_col)) % input->ts->ws_col? 1 : 0);
	while (line--)
		tputs(tgetstr("up", NULL), 0, &ft_putchar2);
	tputs(tgetstr("cr", NULL), 0, ft_putchar2);
	while (col++ < input->cpos.cp_col)
		tputs(tgetstr("nd", NULL), 0, &ft_putchar2);
}


void reset_line(t_input *input)
{
	size_t 	pos;
	size_t 	savepos;

	pos = pos_in_str(input);
	savepos = pos;
	while (savepos--)
		exec_arrow_left(NULL, input);
	redraw_line(input);
	while (pos != pos_in_str(input))
		exec_arrow_right(NULL, input);
}
