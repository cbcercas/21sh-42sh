/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/14 12:30:51 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/main.h>

void	test(t_array *toks)
{
    size_t	cnt;
    t_token	*tok;

    cnt = 0;
    while (cnt < toks->used)
    {
        tok = (t_token *)array_get_at(toks, cnt);
//        ft_printf("tok->str: {%s}\n", tok->str);
//        ft_printf("tok->len: %d\n", tok->len);
        lexer_print_token(tok);
//        ft_putchar('\n');
        ft_putchar('\n');
        cnt++;
    }
}


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
			if (parser_parse(&tokens))
			{
                ft_printf("tokens.used : %d\n", tokens.used);
//                ft_printf("tokens.elem_size : %d\n", tokens.elem_size);
//                ft_printf("tokens.capacity : %d\n", tokens.capacity);
//                ft_printf("exec\n");
                test(&tokens);

			}
		sh_history_set_new(input);
		// if ((command = ft_strsplit(input, ';')))
		// 	if (sh_command(data, command))
		// 		stop = true;
		/***********/
		//char **test = ft_strsplit("history u", ' ');
			//sh_history(NULL, test);
		/***********/

		if (input && ft_strequ(input, "exit"))
			stop = false;
		input ? ft_strdel(&input) : 0;
		array_reset(&tokens, NULL);
		automaton_reset(&automaton);
	}
	sh_history_save();
	sh_deinit(&data);
	ft_putstr("\033[?1049l");
	return (0);
}
