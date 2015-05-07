/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 10:58:39 by amulin            #+#    #+#             */
/*   Updated: 2015/05/07 11:52:07 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int	calc_x(t_tmp *t, t_data *d)
{
	t->x = (t->i - (d->longestline / 2)) * d->spacing + d->left_offset +
		d->left_added * d->spacing;
	return (t->x);
}

int	calc_y(t_tmp *t, t_data *d)
{
	t->y = (t->j - (d->linecount / 2)) * d->spacing + d->top_offset +
		d->top_added * d->spacing;
	return (t->y);
}
