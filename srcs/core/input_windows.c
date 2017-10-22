#include <core/input.h>

/*
 * @brief		Create and manage windows data
 * @param[in]	rst		the reset byte
 * @details		rst can be a byte or an addition of byte like that
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
		rst = 37;
	}
	if (rst >= 20)
		if(!(input_hard_reset(&wd->cur_head)))
			return(NULL);
	if ((rst >= 10 && rst < 20) || rst >= 30)
		input_destroy(&wd->save);
	if ((rst %= 10) && (rst == 1 || rst == 3 || rst == 5 || rst == 7))
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &wd->ts);
	if (rst == 2 || rst == 3 || rst == 6 || rst == 7)
		wd->histlvl = 0;
	if (rst >= 4)
	{
		ft_strdel(&wd->select.str);
		ft_bzero((void *)&wd->select, sizeof(wd->select));
	}
	return (wd);
}

t_select	*get_select(void)
{
	return (&(get_windows(0))->select);
}

struct winsize	*get_ts(void)
{
	return (&(get_windows(0))->ts);
}
