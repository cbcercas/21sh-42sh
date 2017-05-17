/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/17 22:21:44 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/main.h>

int main(int ac, char *const *av)
{

	t_sh_data	data;
	t_automaton	automaton;
	t_array		tokens;
	char		*input;
	BOOL		stop;
	/*sh_init_environ();
	char *tmp = sh_getenv_value("LSCOLORS");
	ft_printf("%s",tmp);*/
	ft_putstr("\033[?1049h\033[H");
	if (!sh_init(&data, ac, av))
		exit(1);
	if (lexer_init(&tokens) == NULL)
		exit (1);
	if (automaton_init(&automaton) == NULL)
		exit (1);
	stop = true;
	while (stop == true)
	{
		sh_print_prompt();
		input = sh_get_line();
		if (input && lexer_lex(&tokens, &automaton, input))
			lexer_print_tokens(&tokens);
		// if ((command = ft_strsplit(input, ';')))
		// 	if (sh_command(data, command))
		// 		stop = true;
		if (input && ft_strequ(input, "exit"))
			stop = false;
		input ? ft_strdel(&input) : 0;
		input ? array_reset(&tokens) : 0;
		automaton_reset(&automaton);
	}
	sh_deinit(&data);
	ft_putstr("\033[?1049l");
	return (0);
}
