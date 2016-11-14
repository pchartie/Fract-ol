/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_mlx		setup_mlx(void)
{
	t_mlx mlx;

	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "Fractol");
	mlx.img = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size, &mlx.endian);
	return (mlx);
}

static t_fractal	*setup_fractal(int i)
{
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal) * 1);
	f->x2 = 2.0;
	f->x1 = -2.0;
	f->y1 = -2.0;
	f->y2 = 1.5;
	f->c_r = -0.8;
	f->c_i = 0.156;
	f->num = i;
	return (f);
}

t_env				*init_struct(int i)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env) * 1);
	e->f = setup_fractal(i);
	e->mlx = setup_mlx();
	e->zoom_x = ((X2 - X1) / (WIDTH - 1));
	e->zoom_y = ((Y2 - Y1) / (HEIGHT - 1));
	e->frequency = 0.1;
	e->iter_max = 16;
	e->color = 4;
	return (e);
}
