/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			red_cross(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	exit(0);
	return (0);
}

static void	make_mandelbrot(int i)
{
	t_env	*e;

	e = init_struct(i);
	draw_fractal(e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_mouse_hook(e->mlx.win, mouse_hook, e);
	mlx_hook(e->mlx.win, 17, (1L << 17), red_cross, e);
	mlx_loop(e->mlx.init);
}

static void	make_julia(int i)
{
	t_env	*e;

	e = init_struct(i);
	draw_fractal(e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_mouse_hook(e->mlx.win, mouse_hook, e);
	mlx_hook(e->mlx.win, MOTION_NOTIFY, PTR_MOTION_MASK,
				motion_hook, e);
	mlx_hook(e->mlx.win, 17, (1L << 17), red_cross, e);
	mlx_loop(e->mlx.init);
}

static void	make_burningship(int i)
{
	t_env	*e;

	e = init_struct(i);
	draw_fractal(e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_mouse_hook(e->mlx.win, mouse_hook, e);
	mlx_hook(e->mlx.win, 17, (1L << 17), red_cross, e);
	mlx_loop(e->mlx.init);
}

int			main(int argc, char **av)
{
	if (argc != 2)
		ft_putstr("usage: ./fractol fractal_number\n");
	else if (ft_strcmp(av[1], "1") == 0)
		make_mandelbrot(1);
	else if (ft_strcmp(av[1], "2") == 0)
		make_julia(2);
	else if (ft_strcmp(av[1], "3") == 0)
		make_burningship(3);
	else
		ft_putstr("mandelbrot: 1\njulia: 2\nburningship: 3\n");
	return (0);
}
