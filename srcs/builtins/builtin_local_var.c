#include <core/data.h>
#include <environ/environ.h>

void builtin_unset(t_sh_data *data, char **argv)
{
	(void) data;
	while (*argv)
	{
		del_var(get_vars(), *argv);
		argv++;
	}
}