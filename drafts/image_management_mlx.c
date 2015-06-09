/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management_mlx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:54:08 by amulin            #+#    #+#             */
/*   Updated: 2015/06/08 15:44:54 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"

typedef struct	s_params
{
	void	*mlx_id;
	void	*win_id;
	void	*img_id;
	char	*img_str;
	int		width;
	int		height;
	int		pixel_size;
	int		*depth;
	int		*size_line;
	int		*endian;
	int		i;
	int		j;
}				t_params;

int	expose_img(t_params *p)
{
	if (p->img_id)
		mlx_put_image_to_window(p->mlx_id, p->win_id, p->img_id, 0, 0);
	return (0);
}

int	fill_str_method(t_params *p)
{
	int	len;
	int	pos;
	int	buf;

	p->img_str = mlx_get_data_addr(p->img_id, p->depth, p->size_line, p->endian);
	pos = 0;
	while (pos < p->width * p->height)
	{
		buf = mlx_get_color_value(p->mlx_id, 0xFFFFFF);
		buf = buf >> 8;
		p->img_str[pos] = buf;
		pos = pos + 1;

//		p->img_str[pos] = mlx_get_color_value(p->mlx_id, 0xFFFFFF);
//		ft_putnbr(p->img_str[pos]);
//		ft_putchar('\n');
//		sleep(1);
//		pos = pos + (p->pixel_size);	
//		pos = pos + sizeof(p->depth);
	}
	len = ft_strlen(p->img_str);
	ft_putnbr(len);
	ft_putchar('\n');
	expose_img(p);
	return (0);
}

int	fill_classic_xy(t_params *p)
{
	int	pos;

	pos = 0;
	p->img_str = mlx_get_data_addr(p->img_id, p->depth, p->size_line, p->endian);
	p->i = 0;
	p->j = 0;
	while (p->j < p->height)
	{
		p->i = 0;
		while (p->i < p->width)
		{
			p->img_str[pos] = mlx_get_color_value(p->mlx_id, 0xFFFFFF);
//			p->img_str[pos + 1] = mlx_get_color_value(p->mlx_id, 0xFFFFFF);
//			p->img_str[pos + 2] = mlx_get_color_value(p->mlx_id, 0xFFFFFF);
//			p->img_str[pos + 3] = mlx_get_color_value(p->mlx_id, 0);
			pos = pos + (p->pixel_size);
			p->i++;
		}
		p->j++;
//		pos = pos + *(p->size_line);
	}
	expose_img(p);
	return (0);
}

int	image_tests(t_params *p)
{
	if (p->img_id)
		mlx_destroy_image(p->mlx_id, p->img_id);
	if ((p->img_id = mlx_new_image(p->mlx_id, p->width / 2, p->height / 2)))
		fill_str_method(p);
	return (0);
}

int	check_key(int keycode, t_params *p)
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
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	p;

	p.img_id = NULL;
	p.pixel_size = sizeof(char) * 3;
	p.depth = (int*)malloc(p.pixel_size);
	*(p.depth) = p.pixel_size;
	p.size_line = (int*)malloc(sizeof(int));
	*(p.size_line) = p.pixel_size * p.width;
	p.endian = (int*)malloc(sizeof(int));
	*(p.endian) = 0;

	if (argc == 3)
	{
		p.width = ft_atoi(argv[1]);
		p.height = ft_atoi(argv[2]);
	}
	else
	{
		p.width = 800;
		p.height = 600;
	}
	ft_putendl("Hello World!");
	p.mlx_id = mlx_init();
	p.win_id = mlx_new_window(p.mlx_id, p.width, p.height, "Check Window");
	mlx_expose_hook(p.win_id, &(expose_img), &p);
	mlx_key_hook(p.win_id, &(check_key), &p);
	mlx_loop(p.mlx_id);
	return (0);
}
