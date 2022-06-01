/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:48:59 by loichu            #+#    #+#             */
/*   Updated: 2022/06/01 15:35:27 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>

typedef	enum	e_fractal {
	Julia,
	Mandlebrot
}	t_fractal;

typedef struct	s_cnb
{
	double	real;
	double	imag;
}	t_cnb;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int			width;
	int			height;
}	t_image;

typedef	struct	s_window {
	void		*mlx;
	void		*win;
	t_image		*img;
	t_fractal	fractal;
}	t_window;

typedef	struct	s_settings {
	int			width;
	int			height;
	t_fractal	fractal;
	t_cnb		c;
	char		*title;
}	t_settings;

typedef struct	s_pnt
{
	int	x;
	int	y;
}	t_pnt;

typedef struct	s_cplan	
{
	double	x_max;
	double	y_max;
	double	zoom;
	t_pnt	center;
}	t_cplan;

// mlx_utils.c
t_window	*init_window(t_settings settings);
t_image		*init_image(t_window *win, t_settings settings);
void		put_image_to_window(t_image *img, t_window *win);

// draw_utils.c
void	pixel_put(t_image *data, int x, int y, int color);

// math_utils,c
double	pow2(double nb);

// atoc.c
t_cnb	ft_atoc(char *cnb);

// fractal.c
t_cnb	proj_cplx_plan(t_pnt pxl, t_cplan plan, t_image *img);

// julia.c
void	draw_julia(t_image *img, t_cplan plan, t_cnb c);

// mandlebrot.c
void	draw_mandlebrot(t_image *img);

// circle.c
void	draw_circle_oct(t_image *img, int xc, int yc, int x, int y, int color);
void	draw_circle(t_image *img, int xc, int yc, int r, int color);

// rectangle.c
void	draw_square(t_image *img, t_pnt orig, int size, int color);
void    draw_rectangle(t_image *img, t_pnt orig, int wid, int hgt, int color);
