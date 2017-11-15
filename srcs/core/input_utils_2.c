/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_bell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:44:30 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/19 06:00:41 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

static void		cpy_input_data(t_input *cpy, t_input *ori)
{
	cpy->prompt_type = ori->prompt_type;
	cpy->prompt_len = ori->prompt_len;
	cpy->offset_col = ori->offset_col;
	ft_memmove(&cpy->cpos, &ori->cpos, sizeof(ori->cpos));
}

void			input_to_save(t_input **to_save, t_input *new_inp)
{
	t_window	*w;

	cpy_input_data(new_inp, *to_save);
	w = get_windows(0);
	if (w->save == NULL)
		w->save = *to_save;
	else
		input_destroy(to_save);
	if (w->save->prev)
		w->save->prev->next = new_inp;
	else
		w->cur_head = new_inp;
	new_inp->prev = w->save->prev;
	w->cur = new_inp;
}

t_input			*input_from_save(t_input **to_destroy)
{
	t_input		*new_inp;
	t_window	*w;

	w = get_windows(0);
	new_inp = get_windows(0)->save;
	cpy_input_data(new_inp, *to_destroy);
	if ((*to_destroy)->prev)
	{
		new_inp->prev = (*to_destroy)->prev;
		new_inp->prev->next = new_inp;
	}
	else
		w->cur_head = new_inp;
	input_destroy(to_destroy);
	w->save = NULL;
	w->cur = new_inp;
	return (new_inp);
}

int				count_nb_input(t_input *input)
{
	int		nb;
	t_input	*tmp;

	nb = 0;
	tmp = input;
	while (input && input->next)
	{
		nb++;
		input = input->next;
	}
	while (tmp && tmp->prev)
	{
		nb++;
		tmp = tmp->prev;
	}
	return (nb);
}

t_input			*input_get_last(t_input *input)
{
	while (input && input->next)
		input = input->next;
	return (input);
}
