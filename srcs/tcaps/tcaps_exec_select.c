/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:17:48 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/18 17:22:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>
#include <core/input.h>

BOOL	exec_select(const t_key *key, t_input *input)
{
  (void)key;
  if (!input->select->is)
  {
    input->select->is = true;
    input->select->cur_start = pos_in_str(input);
    input->select->cur_end = input->select->cur_start;
  }
  else
  {
    input->select->is = false;
    input->select->cur_start = 0;
    input->select->cur_end = 0;
	  //TODO Refactor
    reset_line(input);
  }
  return (false);
}

//TODO replace char *str by is_*_arrow(key->key)
BOOL	exec_select_arrows(const t_key *key, t_input *input, char *str)
{
  t_select			*sel;
  struct winsize	*ts;
  size_t			start;
  size_t			end;

  (void)key;
  sel = get_select();
	ts = get_ts();
  if (input && sel->is && input->str->s && input->str
      && input->str->s[pos_in_str(input)])
  {

    start = sel->cur_start;
    end = sel->cur_end;
    if (str && ((start <= end && ft_strequ("right", str))
                || (start >= end && ft_strequ("left", str))))
     tputs(tgetstr("mr", NULL), 1, &ft_putchar2);
    ft_putchar(input->str->s[pos_in_str(input)]);
    if (input->cpos.cp_col + 1 != ts->ws_col)
      tputs(tgetstr("le", NULL), 0, &ft_putchar2);
    tputs(tgetstr("me", NULL), 1, &ft_putchar2);
  }
  return (false);
}

BOOL	exec_alt_c(const t_key *key, t_input *input)
{
  size_t  start;
  size_t  end;

  (void)key;
  start = input->select->cur_start;
  end = input->select->cur_end;
  if (!input->select->is)
    return (false);
  ft_strdel(&input->select->str);
  if (start < end)
    input->select->str = ft_strsub(input->str->s, start, end - start);
  else if (start > end)
    input->select->str = ft_strsub(input->str->s, end, start - end);
  else
    input->select->str = ft_strsub(input->str->s, start, 1);
  log_info("copie str =[%s]", input->select->str);
  return (false);
}

BOOL	exec_alt_v(const t_key *key, t_input *input)
{
  (void)key;
    if (input->select->is)
      return (false);
  input->str = string_insert(input->str, input->select->str, pos_in_str(input));
	redraw_line(input);
  return (false);
}

BOOL	exec_alt_x(const t_key *key, t_input *input)
{
  size_t  start;
  size_t  end;

  (void)key;
  start = input->select->cur_start;
  end = input->select->cur_end;
  if (!input->select->is)
    return (false);
  exec_alt_c(key, input);
  if (start < end)
    string_remove(input->str, start, end - start);
  else if (start > end)
    string_remove(input->str, end, start - end);
  else
    string_remove(input->str, start, 1);
  redraw_line(input);
  return (false);
}
