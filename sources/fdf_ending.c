/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ending.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:54:04 by amulin            #+#    #+#             */
/*   Updated: 2015/07/01 17:26:45 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ending_routine(t_data *d)
{
	if (d->img->id)
		mlx_destroy_image(d->mlx_id, d->img->id);
	if (d->menu_bg->id)
		mlx_destroy_image(d->mlx_id, d->menu_bg->id);
	free(d->img->endian);
	free(d->img->depth);
	free(d->img->size_line);
	free(d->img);
	free(d->menu_bg);
	free(d->proj);
	d->i = 0;
	while (d->i < d->linecount)
	{
		free(d->rawmap[d->i]);
		d->i++;
	}
	free(d->rawmap);
	free(d->meta);
	mlx_destroy_window(d->mlx_id, d->win_id);
	ft_putendl("\nProgram terminated by user");
	exit(0);
}
