/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:47:05 by jlasne            #+#    #+#             */
/*   Updated: 2017/07/19 10:02:00 by guiforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

/*static void	ft_print_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}*/

BOOL	exec_tab(const t_key *key, t_input *input)
{
	//char *last_word;
	//char **possibilities;

	(void)key;
	(void)input;
	//last_word = autoc_get_last(input->str->s);
	//possibilities = autoc_get_possibilities(last_word);
	//TODO: Cas de "ls TAB" "caTAB" "cd /TAB"
	//ft_print_array(possibilities);
	//exec_ctrl_c(key, input);
	return (false);
}
