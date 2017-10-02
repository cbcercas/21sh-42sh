/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/09/19 12:41:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/echo.h>

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

int		ft_index_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	temp;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (0);
	while (big[i])
	{
		j = 0;
		temp = i;
		if (!i || (big[i - 1] != '\\'))
			while (big[temp] == little[j] && big[temp] && little[j])
			{
				temp++;
				j++;
				if (little[j] == '\0')
					return (i);
			}
		i++;
	}
	return (-1);
}

char	*echo_parse(const char *src)
{
	char	*ret;
	int		index;
	int		i;
	char	car[8][2] = {"\a", "\n", "\r", "\b", "\f", "\t", "\v", "\\"};
	char	res[8][3] = {"\\a", "\\n", "\\r", "\\b", "\\f", "\\t", "\\v", "\\\\"};

	ret = ft_strdup(src);
	i = 0;
	while (i <= 7)
	{
		while(((index = ft_index_strstr(ret, res[i])) != -1))
			ret = ft_replace(ret, car[i], index, 2);
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
		if (flag[1] != 1)
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

	ft_bzero(flag, 2);
	ft_getopt_reset();
	while ((opt = ft_getopt(ft_tablen(argv), argv, "Een")) != -1)
	{
		if(opt == 'n')
			flag[0] = 1;
		else if (opt == 'E' && !flag[1])
			flag[1] = 1;
		else if (opt == 'e' )
			flag[1] = 2;
		else if (opt == '?')
			break ;
	}
	if (opt != '?')
		echo_print(&argv[g_optind], flag);
	if (!(flag[0] && opt != '?'))
		ft_putstr("\n");
	ft_getopt_reset();
	return (((opt != '?') ? 0 : -1));
}
