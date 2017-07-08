/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/07 22:09:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/main.h>

int main(int ac, char *const *av, char **environ)
{

	t_sh_data	data;
	t_automaton	automaton;
	t_array		tokens;
	t_array		expand_array;
	char		*input;
	BOOL		stop;
	//char cwd[1024];

	/*sh_init_environ();
	char *tmp = sh_getenv_value("LSCOLORS");
	ft_printf("%s",tmp);*/
	if (!sh_init(&data, ac, av, environ))
		exit(1);
	if (lexer_init(&tokens) == NULL)
		exit (1);
	if (automaton_init(&automaton) == NULL)
		exit (1);
	if (expand_init(&expand_array) == NULL)
		exit (1);
	stop = true;
	while (stop == true)
	{
		sh_print_prompt();
		input = sh_get_line();
		if (lexer_lex(&tokens, &automaton, input))
			if (parser_parse(&tokens))
			{
				if (expand(&tokens, &expand_array))
					expand_print(&expand_array);
			}
		sh_history_set_new(input);

		// if ((command = ft_strsplit(input, ';')))
		// 	if (sh_command(data, command))
		// 		stop = true;

		/******ECHO*****/
		//char **test = ft_strsplit("echo -e toto\\\\n \\\\ntata", ' ');
		//	sh_echo(NULL, test);
		/***********/


		/*****CD CHDIR******/
		//if (input != NULL)
		//	sh_chdir(NULL, ft_strsplit(input, ' '));
		//getcwd(cwd, sizeof(cwd));
		//ft_printf("%s", cwd);
		/***********/


		/******HELP*****/
		//if (input)
			//sh_builtin_help(&data, ft_strsplit(input, ' '));
		/***********/

		/******SETENV*****/
		//if (input)
			//sh_builtin_unsetenv(&data, ft_strsplit(input, ' '));
		/***********/

		if (input && ft_strequ(input, "exit"))
			stop = false;
		input ? ft_strdel(&input) : 0;
		array_reset(&tokens, NULL);
		array_reset(&expand_array, sh_exp_del);
		automaton_reset(&automaton);
	}
	sh_history_save();
	//sh_expand_destroy(&expand_array);
	sh_deinit(&data);
	ft_putstr("\033[?1049l");
	return (0);
}
