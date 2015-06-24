/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_verbose_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 13:25:15 by amulin            #+#    #+#             */
/*   Updated: 2015/06/24 17:45:43 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_print_loadbar(int pos, int end, int prev, char *mode)
{
	int	status;

	status = my_get_min(100 * pos / end, 100);
	if (!ft_strcmp(mode, "text") && (!pos || status > prev))
	{
		if (pos)
			ft_putchar('\r');
		else
			ft_putchar('\n');
		ft_putstr("[ Status ");
		ft_putnbr(status);
		ft_putstr("% ]");
	}
	if (!ft_strcmp(mode, "bar") && (!pos || status / 5 > prev / 5))
	{
		if (!pos)
			ft_putstr("\n____________________\n");
		else
			ft_putchar('|');
	}
	if (pos == end)
		ft_putendl(" - Done");
	return (status);
}
