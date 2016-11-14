/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchartie <pchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:20:13 by pchartie          #+#    #+#             */
/*   Updated: 2016/02/18 15:11:42 by pchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

# define WIDTH 				512
# define HEIGHT 			512
# define X1					e->f->x1
# define X2					e->f->x2
# define Y1					e->f->y1
# define Y2					e->f->y2
# define MOTION_NOTIFY		6
# define PTR_MOTION_MASK	(1L << 6)

typedef struct	s_fractal
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		image_x;
	double		image_y;
	double		nbr_r;
	double		nbr_i;
	double		mouse_x;
	double		mouse_y;
	int			num;
}				t_fractal;

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}				t_mlx;

typedef struct	s_env
{
	double		frequency;
	double		iter_max;
	double		zoom_x;
	double		zoom_y;
	int			color;
	t_fractal	*f;
	t_mlx		mlx;
}				t_env;

t_env			*init_struct(int i);
int				draw_mandelbrot(t_env *e, int x, int y);
int				draw_julia(t_env *e, int x, int y);
int				draw_burningship(t_env *e, int x, int y);
int				draw_fractal(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				motion_hook(int x, int y, t_env *e);

#endif
