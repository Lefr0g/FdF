/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 16:39:50 by amulin            #+#    #+#             */
/*   Updated: 2015/04/09 16:40:28 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

void	init_t_tmp(t_tmp *t)
{
	t->i = 0;
	t->j = 0;
	t->k = 0;
	t->pos = 0;
	t->prev = 0;
	t->x = 0;
	t->y = 0;
	t->z = 0;
}

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

