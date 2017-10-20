/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:22:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/29 13:24:09 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

pid_t  sh_fork(void)
{
  pid_t pid;

  pid = 0;
  if ((pid = fork()) == -1)
    ft_putstr_fd("fork error\n", 2);
  return (pid);
}
