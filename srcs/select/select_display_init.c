/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 00:16:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/11/03 00:16:43 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/select.h>

static void	*display_check(t_sel_display *disp, size_t wlen)
{
	struct winsize	ts;

	ft_bzero(&ts, sizeof(ts));
	while (ts.ws_col < wlen)
		if (ft_memcmp(&ts, &disp->ts, sizeof(ts)))
		{
			tcaps_bell();
			return (NULL);
		}
		else if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ts) == -1)
			return (select_exit(0, "Failed to get terminal size."));
	ft_memmove(&disp->ts, &ts, sizeof(ts));
	return (disp);
}

void		*dsp_init(void)
{
	t_sel_data	*data;
	t_sel_word	*words;
	size_t		wlen;

	data = select_get_data();
	words = data->words;
	wlen = words->len;
	words = words->next;
	while (words && words != data->words)
	{
		if (wlen < words->len)
			wlen = words->len;
		words = words->next;
	}
	data->disp.col_size = (USHRT)wlen;
	data->disp.word_num = data->words->prev->num + 1;
	if (!display_check(&data->disp, wlen))
		return (NULL);
	data->disp.col_num = (USHRT)(data->disp.ts.ws_col / (wlen + 1));
	ft_bzero(&data->disp.cpos, sizeof(data->disp.cpos));
	data->disp.first = data->words;
	return (data);
}

USHRT		word_get_max_len(t_sel_word *words)
{
	size_t		wlen;
	t_sel_word	*word;

	wlen = words->len;
	word = words->next;
	while (word && word != words)
	{
		if (wlen < word->len)
			wlen = word->len;
		word = word->next;
	}
	return ((USHRT)wlen);
}
