/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/19 17:55:07 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "echo.h"

char	*ms_echo_first_quote(char *str)
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

void ms_echo_cmd(t_ms_data *data, char *arg)
{
	t_command *com;

	com = ms_parse_command(arg);
	ms_command(data, com);
	// TODO free t_command
	ft_printf("command: %s", arg);
}

int ms_echo_parsing(t_ms_data *data, char *arg, int protect)
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
		ms_echo_parsing(data, str, protect);
		(str != tmp) ? ft_strdel(&str) : 0;
		(tmp) ? ft_strdel(&tmp) : 0;
	}
	else if (arg && *arg && c == arg)
	{
		str = ms_extract_str(arg);
		if (*c == '"')
			ms_echo_parsing(data, str, 1);
		else
			ms_echo_cmd(data, str);
		arg += ft_strlen(str) + 2;
		(str) ?ft_strdel(&str) : 0;
	}
	if (arg && *arg != '\0')
		ms_echo_parsing(data, arg, protect);
	return (0);
}

int	ms_echo(t_ms_data *data, char *arg)
{
	int		nl;

	nl = 0;
	if (!ft_strncmp(arg, "-n ", 3))
	{
		arg +=3;
		nl = 1;
	}
	if (ft_strchr(arg, '`') || ft_strchr(arg, '"'))
		ms_echo_parsing(data, arg, 0);
	else
		ft_printf("%s", arg);
	if (!nl)
		ft_putchar('\n');
	return (0);
}
