/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/04/25 10:21:45 by jlasne           ###   ########.fr       */
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
		if (lexer_lex(&tokens, &automaton, input))
			parser_parse(&tokens);
		//lexer_print_tokens(&tokens);
		// if ((command = ft_strsplit(input, ';')))
		// 		// 	if (sh_command(data, command))
		// 				// 		stop = true;
		if (ft_strequ(input, "exit"))
			stop = false;
		array_reset(&tokens);
		automaton_reset(&automaton);
	}
	sh_deinit(&data);
	return (0);
}
