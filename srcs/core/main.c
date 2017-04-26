/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/04 07:14:37 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/main.h>


int main(int ac, char *const *av)
{
	(void)ac;
	(void)av;
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
	logger_init(D_MAX - 1, PROGNAME, "test.log");
	stop = true;
	while (stop == true)
	{
		/*char	buff[MAX_KEY_STRING_LEN];
		int		res;
		t_key key;
		int i;

		raw_terminal_mode();
		(void)ft_bzero((void *)buff, MAX_KEY_STRING_LEN);
		res = read(STDIN_FILENO, buff, MAX_KEY_STRING_LEN);
		buff[res] = '\0';
		key = key_get(buff);
		if (ft_strcmp(key.key_code, KEY_CODE_NONE))
			stop = key_exec(&key);
		else
		if (ft_isprint(key.key[0]))
			ft_printf("%c", key.key[0]);
		key_del(&key);
		if (stop == false && i++ == 10)
			stop = true;
		default_terminal_mode();*/
		sh_print_prompt();
		input = sh_get_line2();
		/*if (lexer_lex(&tokens, &automaton, input))
			lexer_print_tokens(&tokens);*/
		// if ((command = ft_strsplit(input, ';')))
		// 	if (sh_command(data, command))
		// 		stop = true;
		/*if (ft_strequ(input, "exit"))
			stop = false;
		array_reset(&tokens);
		automaton_reset(&automaton);*/
	}
	sh_deinit(&data);
	return (0);
}
