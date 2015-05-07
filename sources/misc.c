/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:39:50 by amulin            #+#    #+#             */
/*   Updated: 2015/05/07 13:49:08 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int		my_get_min(int i, int j)
{
	if (i > j)
		return (j);
	return (i);
}

char	*my_realloc(char **str, int newsize)
{
	free(*str);
	*str = ft_strnew(newsize);
	return (*str);
}

int		my_check_args(int min, int max, int argc, char **argv)
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

int		my_min_one(int num, int denom)
{
	if (num / denom < 1)
		return (1);
	else
		return (num / denom);
}
