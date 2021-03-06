/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:48:59 by loichu            #+#    #+#             */
/*   Updated: 2022/06/09 19:21:34 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef enum e_fractal {
	Julia,
	Mandlebrot
}	t_fractal;

typedef struct s_cnb
{
	double	real;
	double	imag;
}	t_cnb;

typedef struct s_cplan
{
	double	x_max;
	double	y_max;
	double	zoom;
	struct	s_center
	{
		double	x;
		double	y;
	}	center;
}	t_cplan;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_window {
	void		*mlx;
	void		*win;
	t_image		*img;
	t_fractal	fractal;
	t_cnb		c;
	t_cplan		plan;
	int			width;
	int			height;
}	t_window;

typedef struct s_settings {
	int			width;
	int			height;
	t_fractal	fractal;
	t_cnb		c;
	char		*title;
}	t_settings;

typedef struct s_pnt
{
	int	x;
	int	y;
}	t_pnt;

// mlx_utils.c
t_window	*init_window(t_settings settings);
t_image		*init_image(t_window *win);
void		put_image_to_window(t_image *img, t_window *win);
void		destroy_curr_img(t_window *win);

// main.c
int			terminate(t_window *win);

// events.c
int			handle_keydown(int key, t_window *win);
int			handle_close(t_window *win);
int			handle_mouse(int btn, int x, int y, t_window *win);

// draw_utils.c
void		pixel_put(t_image *data, int x, int y, int color);

// atoc.c
t_cnb		ft_atoc(char *cnb);

// fractal.c
t_cnb		proj_cplx_plan(t_pnt pxl, t_cplan plan, t_image *img);
int			get_max_iter(int zoom);
int			get_nb_iter(t_cnb z, t_cnb c, int iter_max);
int			get_pixel_color(int nb_iter, int iter_max);

// julia.c
void		draw_julia(t_image *img, t_cplan plan, t_cnb c);

// mandlebrot.c
void		draw_mandlebrot(t_image *img, t_cplan plan);

#endif
