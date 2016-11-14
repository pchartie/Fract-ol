/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		rainbow(int i, t_env *e)
{
	double	c;
	int		red;
	int		green;
	int		blue;

	if (i == e->iter_max)
		return (0);
	c = e->frequency * (i + 1);
	red = cos(c) * 127 + 128;
	green = cos(c + e->color) * 127 + 128;
	blue = cos(c + e->color + e->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}

static void		put_pixel(t_mlx mlx, int x, int y, int color)
{
	int	bytes;
	int	p;
	int	i;

	i = 0;
	bytes = mlx.bpp / 8;
	p = x * bytes + y * mlx.size;
	while (i < mlx.bpp / 8)
	{
		mlx.data[p + i] = color;
		color >>= 8;
		i++;
	}
}

static int		num_fractal(t_env *e, int x, int y)
{
	if (e->f->num == 1)
		return (draw_mandelbrot(e, x, y));
	else if (e->f->num == 2)
		return (draw_julia(e, x, y));
	else
		return (draw_burningship(e, x, y));
}

int				draw_fractal(t_env *e)
{
	int	color;
	int	num;
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			num = num_fractal(e, y, x);
			color = rainbow(num, e);
			put_pixel(e->mlx, y, x, color);
		}
	}
	mlx_put_image_to_window(e->mlx.init, e->mlx.win, e->mlx.img, 0, 0);
	return (0);
}
