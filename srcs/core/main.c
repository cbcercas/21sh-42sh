/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/13 19:08:00 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>
#include <lexer/lexer.h>
#include <expand/expand.h>
#include <core/input.h>
#include <btree/ft_btree.h>
#include <core/init.h>
#include <builtins/builtin_exit.h>
#include <core/sh_loop.h>
#include <core/main.h>

/*
**!@mainpage 21-42sh Documentation
**
** @section intro_sec Introduction
**
** Welcome to the (doxygen-generated) documentation for 21-42sh \n
** You'll find in here all the documentation, man pages and info about
** our wonderful project started on Jan 15 2017 by *Christopher Bravo Cercas* \n
** and later joined
** by *Jules Lasne*, *Guillaume Pouyat* and *Mathieu Leroy*
**
** @section install_sec Installation
**
** First, you'll need to clone the repository with all the submodules
**
** `git clone --recursive https://github.com/cbcercas/21-42sh.git 21-42sh`
**
** Then just `cd` in the directory and `make`
**
** @subsection step1 Step 1: Opening the box
**
**
** @subsection Environment Environment: When started without an env. These
** are the default values
**
**`TERM` is set to `xterm`
**
**`USER` and `USERNAME` are set to `Marvin`
**
** `PWD` is set to the current cwd value (Gotten with getcwd())
**
**
** If `SHLVL` isnt set, then it's set to `1`. Otherwise it's `+1`
**
**
** WIP *Need to add all the instructions here and add them on README.md to*
*/

t_sh_data			*get_data(t_sh_data *save)
{
	static	t_sh_data	*data = NULL;

	if (save)
		data = save;
	return(data);
}

/*
** @brief Initializes all the arrays needed
**
** @param tokens The token array to initialize
** @param expand The expand array to initialize
*/

static void			sh_arrays_init(t_array *tokens, t_array *expand)
{
	if (lexer_init(tokens) == NULL)
		exit(EXIT_FAILURE);
	if (expand_init(expand) == NULL)
		exit(EXIT_FAILURE);
}

/*
** @brief Main function. Everything starts here
**
** @param ac The argument count
** @param av The argument array
** @param __p__environ The environment
**
** @return Returns a value based on successful exit or not
*/

int				main(int ac, char *const *av, char **environ)
{
	t_sh_data			data;
	struct s_exec_data	exec_dat;
	t_return			ret;
	BOOL				stop;

	stop = false;
	ret = E_RET_NEW_PROMPT;
	exec_dat.ast = NULL;
	if (!isatty(STDIN_FILENO))
		exit (2);
	sh_arrays_init(&exec_dat.tokens, &exec_dat.expand);
	get_data(&data);
	if (!sh_init(get_data(NULL), ac, av, environ))
		exit(1);
	while (!stop)
		stop = sh_loop(data, &exec_dat, &ret);
	sh_arrays_reset(&exec_dat.tokens, &exec_dat.expand);
	if (ret >= E_RET_LEXER_ERROR && ret <= E_RET_LEXER_PIPE)
		ft_dprintf(STDERR_FILENO, "%s: incomplete command\n", PROGNAME);
	sh_exit(&data, NULL);
	return (0);
}
