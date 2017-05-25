#include <core/tcaps.h>

void	redraw_line(t_input *input)
{
	char   *tmp;
	size_t len;
	int    line;
	int    col;


	tmp = input->str->s + ((input->cpos.cp_col + 1) - (input->offset_col + 1)) +
		  (input->ts.ts_cols * input->offset_line);
	len = ft_strlen(tmp);
	line = 0;
	col = input->cpos.cp_col + len;
	//affiche la ligne
	tputs(tmp, (int) len, &ft_putchar2);
	if (len > (size_t)(input->ts.ts_cols - input->cpos.cp_col))
	{
		line =(len - (input->ts.ts_cols - input->cpos.cp_col)) / input->ts.ts_cols + ((len - (input->ts.ts_cols - input->cpos.cp_col)) % input->ts.ts_cols? 1 : 0);
		col  = (len - (input->ts.ts_cols - input->cpos.cp_col)) % input->ts.ts_cols;
	}
	// clear rest of line if needed
	if (col)
		tputs(tgetstr("ce", NULL), 0, ft_putchar2);
	//TODO add tcaps_up(t_input *input, int nb)
	while (line)
	{
		tputs(tgetstr("up", NULL), 0, &ft_putchar2);
		line -= 1;
	}
	tputs(tgetstr("cr", NULL), 0, ft_putchar2);
	col = 0;
	//TODO add tcaps_right(t_input *input, int nb)
	while (col < input->cpos.cp_col)
	{
		tputs(tgetstr("nd", NULL), 0, &ft_putchar2);
		col += 1;
	}
}