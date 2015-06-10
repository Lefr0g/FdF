/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management_mlx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:54:08 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 14:09:42 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"

typedef unsigned int	t_uint32;

typedef struct	s_image
{
	void	*mlx_id;
	void	*win_id;
	void	*img_id;
	char	*img_str;
	int		width;
	int		height;
	int		bytes_per_pixel;
	int		*depth;
	int		*size_line;
	int		*endian;
	int		x;
	int		y;
}				t_image;

int	expose_img(t_image *p)
{
	if (p->img_id)
		mlx_put_image_to_window(p->mlx_id, p->win_id, p->img_id, 0, 0);
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
	return (mlx_get_color_value(img->mlx_id, color));
}

int			image_pixel_put(t_image *img, int x, int y, int color)
{
	t_uint32	mlx_color;
	t_uint32	index;

	mlx_color = rgb_to_mlx(img, color);
	index = x * img->bytes_per_pixel + y * *(img->size_line);
	ft_memcpy(&(img->img_str[index]), &mlx_color, img->bytes_per_pixel);
	return (0);
}

int			fill_str_method(t_image *p)
{
	int			pos;
	t_uint32	color;

	p->img_str = mlx_get_data_addr(p->img_id, p->depth, p->size_line, p->endian);
	pos = 0;
	while (pos < *(p->size_line) * p->height)
	{
		color = mlx_get_color_value(p->mlx_id, 0xFFFFFF);
		if (*(p->endian) == 1)
			color = my_endian_swap(color);
		ft_memcpy(p->img_str + pos, &color, p->bytes_per_pixel);
		pos = pos + p->bytes_per_pixel;
	}
	return (0);
}

int			fill_classic_xy(t_image *p, int color)
{
	p->img_str = mlx_get_data_addr(p->img_id, p->depth, p->size_line, p->endian);
	p->x = 0;
	p->y = 0;
	while (p->y < p->height)
	{
		p->x = 0;
		while (p->x < p->width)
		{
			image_pixel_put(p, p->x, p->y, color);
			p->x++;
		}
		p->y++;
	}
	return (0);
}

int			image_tests(t_image *p)
{
	static int	flag = 0;

	if (p->img_id)
		mlx_destroy_image(p->mlx_id, p->img_id);
	if ((p->img_id = mlx_new_image(p->mlx_id, p->width, p->height)))
	{
//		fill_str_method(p);
		if (!flag)
			fill_classic_xy(p, 0xFFFFFF);
		else if (flag == 1)
			fill_classic_xy(p, 0x00FFFF);
		else if (flag == 2)
			fill_classic_xy(p, 0xFF00FF);
		else if (flag == 3)
		{
			fill_classic_xy(p, 0x000000);
			flag = -1;
		}
		flag++;
		ft_putstr("Flag = ");
		ft_putnbr(flag);
		ft_putchar('\n');
	}
	return (0);
}

int			check_key(int keycode, t_image *p)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx_id, p->win_id);
		exit(0);
	}
	if (keycode == 49)
		image_tests(p);
	expose_img(p);
	return (0);
}

t_image		image_init(int width, int height)
{
	t_image	img;
	
	img.width = width;
	img.height = height;
	img.img_id = NULL;
	img.bytes_per_pixel = 4;
	img.depth = (int*)malloc(sizeof(int));
	*(img.depth) = img.bytes_per_pixel * 8;
	img.size_line = (int*)malloc(sizeof(int));
	*(img.size_line) = img.bytes_per_pixel * img.width;
	img.endian = (int*)malloc(sizeof(int));
	*(img.endian) = 0;
	return (img);
}

int			main(void)
{
	t_image	img;

	img = image_init(800, 200);
	img.mlx_id = mlx_init();
	img.win_id = mlx_new_window(img.mlx_id, img.width, img.height, "Check Window");
	mlx_expose_hook(img.win_id, &(expose_img), &img);
	mlx_key_hook(img.win_id, &(check_key), &img);
	mlx_loop(img.mlx_id);
	return (0);
}
