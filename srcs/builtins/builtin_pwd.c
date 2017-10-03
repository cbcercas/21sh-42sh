/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:02:55 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:03:17 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/pwd.h>

int	sh_builtin_pwd(t_sh_data *data, char **args)
{
	char cwd[1024];

	(void)data;
	if (args && args[1] != NULL)
	{
		ft_printf("pwd: Too many arguments\n");
		return (1);
	}
	getcwd(cwd, sizeof(cwd));
	ft_printf("%s\n", cwd);
	return (0);
}
