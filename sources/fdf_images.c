/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:54:08 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 16:13:53 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_v2.h"

int			expose_img(t_data *d, int x, int y)
{
	if (d->img->id)
		mlx_put_image_to_window(d->mlx_id, d->win_id, d->img->id, x, y);
	return (0);
}

t_uint32	my_endian_swap(unsigned int input)
{
	t_uint32	output;

	if (sizeof(input) != 4)
	{
		ft_putendl("error: int size not supported. End of program");
		exit(0);
	}
	output = (input << 24);
	output |= ((input << 8) & 0x00FF0000);
	output |= ((input >> 8) & 0x0000FF00);
	output |= (input >> 24);
	return (output);
}

t_uint32	rgb_to_mlx(t_image *img, int color)
{
	t_uint32	color_out;

	if (*(img->endian) == 1)
		color_out = my_endian_swap(color);
	return (mlx_get_color_value(img->mlx, color));
}

int			image_pixel_put(t_image *img, int x, int y, int color)
{
	t_uint32	mlx_color;
	t_uint32	index;

	mlx_color = rgb_to_mlx(img, color);
	index = x * img->bytes_per_pixel + y * *(img->size_line);
	ft_memcpy(&(img->str[index]), &mlx_color, img->bytes_per_pixel);
	return (0);
}
