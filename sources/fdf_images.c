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

t_uint32	rgb_to_mlx(t_data *d, int color)
{
	t_uint32	color_out;

	if (*(d->img->endian) == 1)
		color_out = my_endian_swap(color);
	return (mlx_get_color_value(d->mlx_id, color));
}

int			image_pixel_put(t_data *d, int x, int y, int color)
{
	t_uint32	mlx_color;
	t_uint32	index;

	mlx_color = rgb_to_mlx(d, color);
	index = x * d->img->bytes_per_pixel + y * *(d->img->size_line);
	ft_memcpy(&(d->img->str[index]), &mlx_color, d->img->bytes_per_pixel);
	return (0);
}

t_image		image_init(int width, int height)
{
	t_image	img;

	img.x = 0;
	img.y = 0;
	img.endian = (int*)malloc(sizeof(int));
	*(img.endian) = 0;
	img.width = width;
	img.height = height;
	img.id = NULL;
	img.bytes_per_pixel = 4;
	img.depth = (int*)malloc(sizeof(int));
	*(img.depth) = img.bytes_per_pixel * 8;
	img.size_line = (int*)malloc(sizeof(int));
	*(img.size_line) = img.bytes_per_pixel * img.width;
	return (img);
}
