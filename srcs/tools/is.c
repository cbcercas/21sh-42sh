/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 11:43:17 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 15:15:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tools/tools.h>

/*
** @brief Checks if a char is a space or a tab
**
** @param c Char to be checked
**
** @return Returns true if `c` is a tab or a space, false otherwise
*/

BOOL  is_white(int c)
{
	if (c == '\t' || c == '\v' || c == ' ')
		return (true);
	return (false);
}

/*
** @brief Checks the first and only letter of the string buff for a char
** @param buff string containing a char to be tester
** @return Returns true if buff[0] contains a letter, false otherwise
*/

BOOL  is_str_car(const char *buff)
{
  if (buff[0] > 31 && buff[0] < 127 && buff[1] == 0)
    return (true);
  return (false);
}

/*
** @brief Checks if the token `c` is a redirection
** @param c Token to be checked
** @return Returns true if `c` is a redirection token or false otherwise
*/

BOOL  is_redirect(int c)
{
	if (c == E_TOKEN_LESSGREAT || c == E_TOKEN_DLESS || c == E_TOKEN_DGREAT ||
				c == E_TOKEN_DGREAT || c == E_TOKEN_GREATAND || c == E_TOKEN_LESSAND)
		return (true);
	return (false);
}

/*
** @brief Checks if the token `c` is a separator
** @param c Token to be checked
** @return Returns true if `c` is a separator token or false otherwise
*/

BOOL  is_sepa(int c)
{
	if (c == E_TOKEN_SEMI || c == E_TOKEN_AND_IF || c == E_TOKEN_OR_IF
		|| c == E_TOKEN_NEWLINE)
	return (true);
return (false);
}
