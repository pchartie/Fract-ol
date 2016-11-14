/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_mouse(int button, int x, int y, t_env *e)
{
	if ((button == 1 || button == 4) && x <= WIDTH && y <= HEIGHT)
	{
		e->f->c_r /= 1.5;
		e->f->c_i /= 1.5;
	}
	else if ((button == 2 || button == 5) && x <= WIDTH && y <= HEIGHT)
	{
		e->f->c_r *= 1.5;
		e->f->c_i *= 1.5;
	}
	return ;
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	double	tmp_r;
	double	tmp_i;

	tmp_r = x;
	tmp_i = y;
	e->f->c_r = X2 - X1;
	e->f->c_i = Y2 - Y1;
	e->f->mouse_x = ((double)x / WIDTH * e->f->c_r)
						- e->f->c_r / 2 + e->f->mouse_x;
	e->f->mouse_y = (double)(HEIGHT - y) / HEIGHT
						* e->f->c_i - e->f->c_i / 2 + e->f->mouse_y;
	zoom_mouse(button, x, y, e);
	tmp_r = e->f->c_r / 2;
	tmp_i = e->f->c_i / 2;
	X1 = e->f->mouse_x - tmp_r;
	X2 = e->f->mouse_x + tmp_r;
	Y1 = e->f->mouse_y - tmp_i;
	Y2 = e->f->mouse_y + tmp_i;
	e->zoom_y = ((Y2 - Y1) / (HEIGHT - 1));
	e->zoom_x = ((X2 - X1) / (WIDTH - 1));
	draw_fractal(e);
	return (0);
}

int			motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		e->f->c_r = X1 + (double)x * e->zoom_x;
		e->f->c_i = Y2 - (double)y * e->zoom_y;
	}
	else
		return (0);
	return (draw_fractal(e));
}

static void	translate(t_env *e, int keycode)
{
	if (keycode == 1)
	{
		Y2 -= e->zoom_x * 10;
		Y1 -= e->zoom_x * 10;
	}
	else if (keycode == 13)
	{
		Y2 += e->zoom_x * 10;
		Y1 += e->zoom_x * 10;
	}
	else if (keycode == 0)
	{
		X2 -= e->zoom_x * 10;
		X1 -= e->zoom_x * 10;
	}
	else if (keycode == 2)
	{
		X2 += e->zoom_x * 10;
		X1 += e->zoom_x * 10;
	}
	e->zoom_y = ((Y2 - Y1) / (HEIGHT - 1));
	e->zoom_x = ((X2 - X1) / (WIDTH - 1));
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 24)
		e->iter_max = e->iter_max * 2;
	else if (keycode == 27)
		e->iter_max = e->iter_max / 2;
	translate(e, keycode);
	draw_fractal(e);
	return (0);
}
