/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/08 18:17:28 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <core/main.h>

int main(int ac, char *const *av, char **environ)
{
	t_sh_data	data;
	t_automaton	automaton;
	t_array		tokens;
	char		*input;
	BOOL		stop;

	stop = false;
	if (!sh_init(&data, ac, av, environ))
		exit(1);
	if (lexer_init(&tokens) == NULL)
		exit (1);
	if (automaton_init(&automaton) == NULL)
		exit (1);
	while (stop == false)
	{
		sh_print_prompt();
		input = sh_get_line();
		sh_history_set_new(input);
		if (lexer_lex(&tokens, &automaton, input))
			if (parser_parse(&tokens))
				;
		if (input && ft_strequ(input, "exit"))
			stop = true;
		input ? ft_strdel(&input) : 0;
		sh_reset_line(&automaton, &tokens);
	}
	sh_history_save();
	sh_deinit(&data);
	return (0);
}
