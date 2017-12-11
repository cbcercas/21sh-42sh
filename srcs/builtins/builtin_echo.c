/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:31:13 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 14:36:05 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_echo.h>

extern int g_optind;

/*
** @brief Replaces in src1 from index until size with scr2
**
** @param src1 String to modify
** @param src2 String used to modify
** @param index Where to start
** @param size how long should it replace
**
** @return Returns the modified string
*/

static char	*ft_replace(char *src1, char *src2, int index, int size)
{
	char	*begin;
	char	*end;
	char	*ret;

	begin = ft_strnew((size_t)index);
	begin = ft_strncpy(begin, src1, (size_t)index);
	end = ft_strjoin(src2, &src1[index + size]);
	ret = ft_strjoin(begin, end);
	free(begin);
	free(end);
	free(src1);
	return (ret);
}

/*
** @brief Searches for occurrence of `little` in string `big`
**
** @param big The string in which the function will search for `little`
** @param little The string to search in `big`
**
** @return Returns the index of where `little` starts in `big`
*/

static int	ft_index_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	temp;

	i = 0;
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

/*
** @brief Parses the `\\`x for echo
**
** @param src The string to parse
**
** @return Returns the parsed string
*/

static char	*echo_parse(const char *src)
{
	char		*ret;
	int			index;
	int			i;
	static char	car[8][2] = {"\a", "\n", "\r", "\b", "\f", "\t", "\v", "\\"};
	static char	res[8][3] = {"\\a", "\\n", "\\r", "\\b", "\\f", "\\t", "\\v",\
																		"\\\\"};

	ret = ft_strdup(src);
	i = 0;
	while (i <= 7)
	{
		while (((index = ft_index_strstr(ret, res[i])) != -1))
			ret = ft_replace(ret, car[i], index, 2);
		i++;
	}
	return (ret);
}

/*
** @brief Prints what the user asked
**
** @param arg The args passed to echo
** @param flag is option
** -n flag[0] = 1 , 0 otherwise
** -e flag[1] = 1 , 0 or 2 otherwise
** -E flag[1] = 2 , 0 or 1 otherwise
**
** @return Void
*/

static void	echo_print(char **arg, const char flag[2])
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (arg && arg[i])
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
		if (arg[i])
			ft_printf("%s", " ");
	}
}

/*
** @brief The function called when echo is executed
** @param data The shell data used throughout the program
** @param argv The args passed to echo
**
** @return Returns the ret value of echo
*/

int			sh_echo(t_sh_data *data, char **argv)
{
	int		opt;
	char	flag[2];

	(void)data;
	ft_bzero(flag, 2);
	ft_getopt_reset();
	while ((opt = ft_getopt(((int)ft_tablen(argv)), argv, "Een")) != -1)
	{
		if (opt == 'n')
			flag[0] = 1;
		else if (opt == 'E' && !flag[1])
			flag[1] = 1;
		else if (opt == 'e')
			flag[1] = 2;
		else if (opt == '?')
			break ;
	}
	if (opt != '?')
		echo_print(&argv[g_optind], flag);
	if (!(flag[0] && opt != '?') && opt != '?')
		ft_putstr("\n");
	ft_getopt_reset();
	return (((opt != '?') ? 0 : 1));
}
