/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:48:59 by loichu            #+#    #+#             */
/*   Updated: 2022/05/17 15:32:12 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

typedef struct	s_window {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_window;

typedef struct	s_cnb
{
	double	real;
	double	imag;
}	t_cnb;

typedef struct	s_pnt
{
	int	x;
	int	y;
}	t_pnt;

// mlx_utils.c
t_window	*init_window(int width, int height, int bg_color, char *title);

// draw_utils.c
void	pixel_put(t_window *data, int x, int y, int color);

// circle.c
void	draw_circle_oct(t_window *data, int xc, int yc, int x, int y, int color);
void	draw_circle(t_window *data, int xc, int yc, int r, int color);

// rectangle.c
void	draw_square(t_window *data, t_pnt orig, int size, int color);
void    draw_rectangle(t_window *data, t_pnt orig, int wid, int hgt, int color);
