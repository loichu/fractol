/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:48:59 by loichu            #+#    #+#             */
/*   Updated: 2022/04/26 17:28:04 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <mlx.h>

typedef struct	s_window {
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

// draw_utils.c
void	pixel_put(t_window *data, int x, int y, int color);

// circle.c
void	draw_circle_oct(t_window *data, int xc, int yc, int x, int y, int color);
void	draw_circle(t_window *data, int xc, int yc, int r, int color);

// rectangle.c
void	draw_square(t_window *data, int x, int y, int size, int color);
