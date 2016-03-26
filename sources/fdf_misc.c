/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:39:50 by amulin            #+#    #+#             */
/*   Updated: 2016/03/26 16:47:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_file_drawable(t_data *d)
{
	if (!d->linecount || !d->longestline)
	{
		ft_putendl("\nThis file appears empty, nothing will be drawn.");
		ft_putendl("Terminating program.");
		exit(1);
	}
}

int		my_get_min(int i, int j)
{
	if (i > j)
		return (j);
	return (i);
}

char	*my_realloc(char **str, int newsize)
{
	ft_strdel(str);
	*str = ft_strnew(newsize);
	return (*str);
}

int		my_min_one(int num, int denom)
{
	if (num / denom < 1)
		return (1);
	else
		return (num / denom);
}
