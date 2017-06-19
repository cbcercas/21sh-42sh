//
// Created by seluj78 on 16/06/17.
//

#include <builtins/help.h>

int sh_builtin_help(t_sh_data *data, char **args)
{
	(void)args;
	(void)data;
	ft_printf("Hi ! I'm help, how can i help ?\n");
	return (0);
}