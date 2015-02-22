/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 11:06:47 by amulin            #+#    #+#             */
/*   Updated: 2015/02/17 14:34:21 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include <mlx.h>
# include <stdio.h>

typedef	struct	s_params
{
	void	*id;
	void	*win;
	int		***mapcpy;
	int		spacing;
	int		left_offset;
	int		top_offset;
	float	cte1;
	float	cte2;
	int		X1;
	int		Y1;
	int		X2;
	int		Y2;
	int		tbd_flag;
}				t_params;

#endif
