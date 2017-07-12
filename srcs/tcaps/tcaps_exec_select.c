/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcaps_exec_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:17:48 by gpouyat           #+#    #+#             */
/*   Updated: 2017/07/12 21:50:23 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tcaps.h>

BOOL	exec_select(const t_key *key, t_input *input)
{
  if (!input->select.is)
  {
    input->select.is = true;
    input->select.cur_start = sh_pos_of_insert(*input);
  }
  else
  {
    input->select.is = false;
    input->select.cur_start = 0;
    input->select.cur_end = 0;
    redraw_line(input);
  }
  return (false);
}

BOOL	exec_select_arrows(const t_key *key, t_input *input, char *str)
{
  t_cpos  save;
  size_t  start;
  size_t  end;

  (void)key;
  start = input->select.cur_start;
  end = input->select.cur_end;
  if (input->select.is && input->str->s &&\
     input->str->s[sh_pos_of_insert(*input)])
  {
    tputs(tgetstr("dm", NULL), 0, &ft_putchar2);
    tputs(tgetstr("dc", NULL), 0, &ft_putchar2);
    tputs(tgetstr("de", NULL), 0, &ft_putchar2);
    if (str && ((start <= end && ft_strequ("right", str)) ||\
     (start >= end && ft_strequ("left", str))))
    tputs(tgetstr("mr", NULL), 1, ft_putchar2);
    ft_putchar(input->str->s[sh_pos_of_insert(*input)]);
    save = input->cpos;
    move_cursor_left(&input->cpos, &input->ts);
    input->cpos = save;
    tputs(tgetstr("me", NULL), 1, ft_putchar2);
  }
  return (false);
}

BOOL	exec_alt_c(const t_key *key, t_input *input)
{
  size_t  start;
  size_t  end;

  (void)key;
  start = input->select.cur_start;
  end = input->select.cur_end;
  if (!input->select.is)
    return (false);
  ft_strdel(&input->select.str);
  if (start < end)
    input->select.str = ft_strsub(input->str->s, start, end - start);
  else if (start > end)
    input->select.str = ft_strsub(input->str->s, end, start - end);
  else
    input->select.str = ft_strsub(input->str->s, start, 1);
  log_info("copie str =[%s]", input->select.str);
  return (false);
}

BOOL	exec_alt_v(const t_key *key, t_input *input)
{
  (void)key;
    if (input->select.is)
      return (false);
  input->str = string_insert(input->str, input->select.str, sh_pos_of_insert(*input));
  redraw_line(input);
  return (false);
}

BOOL	exec_alt_x(const t_key *key, t_input *input)
{
  size_t  start;
  size_t  end;

  (void)key;
  start = input->select.cur_start;
  end = input->select.cur_end;
  if (!input->select.is)
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
