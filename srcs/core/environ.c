/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:20:28 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 09:34:25 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
extern char **environ;
#include "environ.h"

t_env	*cbc_copy_environ(void)
{
	t_env	*head;
	t_env	*e;

	head = NULL;
	while(*environ)
	{
		if (!head)
		{
			if (!(head = cbc_new_env(*environ)))
				// TODO add error function malloc
				return (NULL);
			e = head;
		}
		else if (e && !(e->next = cbc_new_env(*environ)))
			// TODO add error function malloc
			return (NULL);
		else
			e = e->next;
		environ++;
	}
	return (head);
}