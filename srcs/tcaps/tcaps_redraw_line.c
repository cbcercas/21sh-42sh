#include <core/tcaps.h>
#include <core/input.h>

void	redraw_line(t_input *input)
{
	char   *tmp;
	int		len;
	int		line;
	int		col;


	tmp = input->str->s + ((((input->cpos.cp_col + 1) - (input->offset_col + 1)) +
		  (input->ts->ws_col * input->offset_line)));
	len = (int)ft_strlen(tmp);
	line = 0;
	col = 0;
	// clear rest of line if needed
	tputs(tgetstr("ce", NULL), 0, ft_putchar2);
	if ( len + 1 > (input->ts->ws_col - input->cpos.cp_col))
	{
		tputs(tgetstr("do", NULL), 0, ft_putchar2);
		tputs(tgetstr("cr", NULL), 0, ft_putchar2);
		tputs(tgetstr("cd", NULL), 0, ft_putchar2);
		tputs(tgetstr("up", NULL), 0, ft_putchar2);
		while (col < input->cpos.cp_col)
		{
			tputs(tgetstr("nd", NULL), 0, &ft_putchar2);
			col += 1;
		}
	}
	//affiche la ligne
	tputs(tmp, (int) len, &ft_putchar2);
	col = input->cpos.cp_col + len;
	if (len > (input->ts->ws_col - input->cpos.cp_col))
	{
		line =(len - (input->ts->ws_col - input->cpos.cp_col)) / input->ts->ws_col + ((len - (input->ts->ws_col - input->cpos.cp_col)) % input->ts->ws_col? 1 : 0);
		col  = (len - (input->ts->ws_col - input->cpos.cp_col)) % input->ts->ws_col;
	}
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

void reset_line()
{
	size_t 	pos;
	size_t 	savepos;

	pos = pos_in_str(g_input);
	savepos = pos;
	while (savepos--)
		exec_arrow_left(NULL, g_input);
	redraw_line(g_input);
	while (pos != pos_in_str(g_input))
		exec_arrow_right(NULL, g_input);
};
