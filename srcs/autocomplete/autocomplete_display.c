/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:30:33 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/10 12:31:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <autocomplete/autocomplete.h>

//TODO Refactor with new input design (draw_input())
void		autocomplete_display(t_array *content)
{
	if (!content || !content->used || content->used == 1)
		return ;
	if (!autocomplete_get_repons(content->used))
		return ;
	default_terminal_mode();
	ft_putchar('\n');
	autocomplete_display_cols(content);
	ft_printf("\n");
	//why redraw prompt
	autocomplete_display_prompt(get_windows(0)->cur);
	raw_terminal_mode();
}

//TODO Refactor reset input, split history, print
//TODO Refactor with new input design
void		autocomplete_display_prompt(t_input *input)
{
	size_t	pos;

	pos = 0;
	pos = pos_in_str(input);
	//input->offset_col = sh_len_prompt();
	//input->offset_line = 0;
	//input->cpos.cp_line = 0;
	get_select()->is = false;
	//input->cpos.cp_col = (unsigned short)input->offset_col;
	sh_print_prompt(input, NULL, 0);
	redraw_line(input);
	while (pos != pos_in_str(input))
		exec_arrow_right(NULL, input);
}

void		autocomplete_display_input(t_input *input, int len)
{
	tputs(tgetstr("cr", NULL), 1, ft_putchar2);
	autocomplete_display_prompt(input);
	while (len--)
		exec_arrow_right(NULL, input);
}
