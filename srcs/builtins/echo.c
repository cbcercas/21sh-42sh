/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/02/26 16:02:38 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/echo.h>

/*char	*ms_echo_first_quote(char *str)
{
	char	*q;
	char	*dq;

	q = ft_strchr(str, '`');
	dq = ft_strchr(str, '"');
	if (!dq || (q && q < dq))
		return (q);
	else
		return (dq);
}

void ms_echo_cmd(t_sh_data *data, char *arg)
{
	char **cmd;

	ft_printf("arg: >%s<", arg);
	if ((cmd = ft_strsplit(arg, ';')))
		if (sh_command(data, cmd))
			return;
	ft_freetab(cmd, ft_tablen(cmd));
}

static int sh_echo_parsing(t_sh_data *data, char *arg, int protect)
{
	char	*c;
	char	*str;
	char	*tmp;

	if (arg && *arg && !(c = ms_echo_first_quote(arg)))
	{
		ft_putstr(arg);
		return (0);
	}
	else if (arg && *arg && c != arg)
	{
		tmp = ft_strsub(arg, 0, c - arg);
		// TODO write ft_str whitespace cleanup with free
		arg += c - arg;
		str = (protect || !ft_strcmp(tmp, " ")) ? tmp : ft_strtrim(tmp);
		sh_echo_parsing(data, str, protect);
		(str != tmp) ? ft_strdel(&str) : 0;
		(tmp) ? ft_strdel(&tmp) : 0;
	}
	else if (arg && *arg && c == arg)
	{
		str = sh_extract_str(arg);
		if (*c == '"')
			sh_echo_parsing(data, str, 1);
		else
			ms_echo_cmd(data, str);
		arg += ft_strlen(str) + 2;
		(str) ?ft_strdel(&str) : 0;
	}
	if (arg && *arg != '\0')
		sh_echo_parsing(data, arg, protect);
	return (0);
}

int	sh_echo(t_sh_data *data, char *arg)
{
	int		nl;

	nl = 0;
	if (!ft_strncmp(arg, "-n ", 3))
	{
		arg +=3;
		nl = 1;
	}
	if (ft_strchr(arg, '`') || ft_strchr(arg, '"'))
		sh_echo_parsing(data, arg, 0);
	else
		ft_printf("%s", arg);
	if (!nl)
		ft_putchar('\n');
	return (0);
}*/
char	*ft_replace(char *src1, char *src2, int index, int size)
{
	char	*begin;
	char	*end;
	char	*ret;

	begin = ft_strnew(index);
	begin = ft_strncpy(begin, src1, index);
	end = ft_strjoin(src2, &src1[index + size]);
	ret = ft_strjoin(begin, end);
	free(begin);
	free(end);
	free(src1);
	return (ret);
}

int		ft_index_chr(const char *s, int c)
{
	char c2;
	int		i;

	i = 0;
	c2 = (char)c;
	while (*s != c2)
	{
		if (*s == '\0')
			return (-1);
		s++;
		i++;
	}
	return (i);
}

char	*echo_parse(const char *src)
{
	char	*ret;
	int		index;
	int		i;
	int	car[7] = {'\a', '\n', '\r', '\b', '\f', '\t', '\v'};
	char	res[7][3] = {"\\a", "\\n", "\\r", "\\b", "\\f", "\\t", "\\v"};

	ret = ft_strdup(src);
	i = 0;
	while (i <= 6)
	{
		//log_dbg3("User pressed backspace");
		log_dbg1("salut i =%d, car=%d res=%s", i, car[i], res[i]);
		while((index = ft_index_chr(ret, car[i])) != -1)
		{
			ret = ft_replace(ret, res[i], index, 1);
		}
		i++;
	}
	return (ret);
}

void	echo_print(char **arg, char flag[2])
{
	unsigned int		i;
	char	*tmp;

	i = 0;
	while(arg && arg[i])
	{
		if (flag[1] == 1)
		{
			tmp = echo_parse(arg[i]);
			ft_printf("%s", tmp);
			ft_strdel(&tmp);
		}
		else
			ft_printf("%s", arg[i]);
		i++;
		if(arg[i])
			ft_printf("%s", " ");
	}
}

int sh_echo(t_sh_data *data, char **argv)
{
	(void)data;
	int		opt;
	char	flag[2]; //0 => n,  1 => e

	//TODO : reset get_opt
	opterr = 1;
	optind = 1;
	optarg = NULL;

	ft_bzero(flag, 2);
	while ((opt = getopt(ft_tablen(argv), argv, "Een")) != -1) //TODO:change for ft_getopt
	{
		if(opt == 'n')
			flag[0] = 1;//sh_history_builtin_n(argv[optind]);
		else if (opt == 'E' && !flag[1])
			flag[1] = 1;
		else if (opt == 'e' )
			flag[1] = 2;
		else if (opt == '?')
			break ;//sh_history_help(argv[1]);
	}
	echo_print(&argv[optind], flag);
	if (!flag[0])
		ft_putstr("\n");
	//TODO : reset get_opt
	return (0);
}
