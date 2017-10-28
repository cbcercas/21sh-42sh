#include <core/input.h>

t_window	*get_windows2(t_window *wd, int rst)
{
	if ((rst %= 10) && rst >= 4)
	{
		ft_strdel(&wd->select.str);
		ft_bzero((void *)&wd->select, sizeof(wd->select));
	}
	if ((rst %= 4) && rst >= 2)
		wd->histlvl = -1;

	if ((rst %= 2) && rst == 1)
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &wd->ts);
	return (wd);
}
/*
 * @brief		Create and manage windows data
 * @param[in]	rst		the reset byte
 * @details		rst can be a byte or an addition of byte like that
 *				40	reset histlock
 * 				20	hard reset current input
 * 				10	destroy saved input
 * 				4	reset the selection data
 * 				2	reset history level
 * 				1	reset windows size
 * 				example:
 * 				to reset current and save input and history level:
 * 				rst = 32 = 20 + 10 + 2
 * 				to reset everything:
 * 				rst = 37 = 20 + 10 + 4 + 2 + 1
 * @return
 */

t_window	*get_windows(int rst)
{
	static	t_window	*wd = NULL;

	if (wd && !rst)
		return (wd);
	if (!(wd))
	{
		if (!(wd = ft_memalloc(sizeof(*wd))))
			exit(1);
		rst = 77;
	}
	if (rst >= 40)
		wd->histlock = false;
	if ((rst %= 40) && rst >= 20)
		if(!(input_hard_reset(&wd->cur_head)))
			return(NULL);
	if ((rst %= 20) && rst >= 10)
		input_destroy(&wd->save);
	return (get_windows2(wd, rst));
}

t_select	*get_select(void)
{
	return (&(get_windows(0))->select);
}

struct winsize	*get_ts(void)
{
	return (&(get_windows(0))->ts);
}

t_input	*input_get_cur_head(void)
{
	t_window	*w;

	w = get_windows(0);
	return (w->cur_head);
}

t_input	*input_get_cur(void)
{
	t_window	*w;

	w = get_windows(0);
	return (w->cur);
}