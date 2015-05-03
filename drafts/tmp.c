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

int	main(int argc, char **argv)
{
	int	i;

	if (my_check_args(1, 2, argc, argv))
	{
		ft_putendl("Check arguments");
		return (-1);
	}
	i = sizeof(int);
	ft_putnbr(i);
	ft_putchar('\n');
	return (0);
}
