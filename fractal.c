/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_mandelbrot(t_env *e, int x, int y)
{
	t_fractal	*f;
	int			i;

	i = -1;
	f = e->f;
	f->nbr_i = 0;
	f->nbr_r = 0;
	f->image_x = X1 + (double)x * e->zoom_x;
	f->image_y = Y2 - (double)y * e->zoom_y;
	f->z_r = f->nbr_r * f->nbr_r;
	f->z_i = f->nbr_i * f->nbr_i;
	while (++i < e->iter_max && (f->z_r + f->z_i < 4))
	{
		f->nbr_i *= f->nbr_r;
		f->nbr_i += f->nbr_i + f->image_y;
		f->nbr_r = f->z_r - f->z_i + f->image_x;
		f->z_r = f->nbr_r * f->nbr_r;
		f->z_i = f->nbr_i * f->nbr_i;
	}
	return (i);
}

int	draw_julia(t_env *e, int x, int y)
{
	t_fractal	*f;
	int			i;

	i = -1;
	f = e->f;
	f->nbr_i = Y2 - (double)y * e->zoom_y;
	f->nbr_r = X1 + (double)x * e->zoom_x;
	f->z_r = f->nbr_r * f->nbr_r;
	f->z_i = f->nbr_i * f->nbr_i;
	while (++i < e->iter_max && (f->z_r + f->z_i) < 4)
	{
		f->nbr_i *= f->nbr_r;
		f->nbr_i += f->nbr_i + f->c_i;
		f->nbr_r = f->z_r - f->z_i + f->c_r;
		f->z_r = f->nbr_r * f->nbr_r;
		f->z_i = f->nbr_i * f->nbr_i;
	}
	return (i);
}

int	draw_burningship(t_env *e, int x, int y)
{
	t_fractal	*f;
	int			i;

	i = -1;
	f = e->f;
	f->image_x = X1 + (double)x * e->zoom_x;
	f->image_y = Y2 - (double)y * e->zoom_y;
	f->nbr_r = f->image_x;
	f->nbr_i = f->image_y;
	f->z_r = f->nbr_r * f->nbr_r;
	f->z_i = f->nbr_i * f->nbr_i;
	while (++i < e->iter_max && (f->z_r + f->z_i) < 4)
	{
		f->nbr_i = 2 * fabs(f->nbr_r * f->nbr_i);
		f->nbr_i -= f->image_y;
		f->nbr_r = f->z_r - f->z_i + f->image_x;
		f->z_r = f->nbr_r * f->nbr_r;
		f->z_i = f->nbr_i * f->nbr_i;
	}
	return (i);
}
