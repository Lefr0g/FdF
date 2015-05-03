/**************************************************************************
 * 
 *
 *
 *
 *
 *
 *
 *
 *
*/

#include "libft.h"
#include "fdf_v2.h"

#include <stdio.h>

int	my_check_args(int min, int max, int argc, char **argv)
{
	if (min > max || min < 0 || max < 0 || argc < 1 || !argv)
		return (-1);
	if (argc < min)
		return (1);
	else if (argc > max)
		return (2);
	else
		return (0);
}

int	my_print_loadbar(int pos, int end, int prev, char *mode)
{
	int	status;

	status = 100 * pos / end;
	if (!ft_strcmp(mode, "text") && (!pos || status > prev))
	{
		if (pos)
			ft_putchar('\r');
		ft_putstr("Loading ");
		ft_putnbr(status);
		ft_putstr("%");
	}
	if (!ft_strcmp(mode, "bar") && (!pos || status / 5 > prev / 5))
	{
		if (!pos)
			ft_putstr("Loading\n____________________\n");
		else
			ft_putchar('|');
		if(pos == end)
			ft_putendl("\nComplete");
	}
	if (pos == end)
		ft_putchar('\n');
	return (status);
}

int	main(int argc, char **argv)
{
	int	i;
	int	max;
	int	status;
	int	prev;

	if (my_check_args(2, 2, argc, argv))
	{
		ft_putendl("Check arguments");
		return (-1);
	}
	i = 0;
	max = 1000;
	prev = 0;
	while (i <= max)
	{
		usleep(2000);
		prev = status;
		status = my_print_loadbar(i, max, prev, "text");
		i++;
	}
	return (0);
}
