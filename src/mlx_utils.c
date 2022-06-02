/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:16:09 by loichu            #+#    #+#             */
/*   Updated: 2022/06/02 18:58:56 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_image		*init_image(t_window *win, t_settings settings)
{
	t_image		*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->width = settings.width;
	img->height = settings.height;
	img->img = mlx_new_image(win->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(
		img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	return (img);
}

t_window	*init_window(t_settings settings)
{
	t_window	*win;
	
	printf("%s\n", settings.title);
	win = (t_window *)malloc(sizeof(t_window));
	win->mlx = mlx_init();
	win->win = mlx_new_window(
			win->mlx, settings.width, settings.height, settings.title);
	win->img = NULL;
	win->plan.x_max = 2.1;
	win->plan.zoom = 1;
	//cplan.center = (struct s_center){.x=0, .y=0};
	//cplan.center = (struct s_center){.x=-0.6, .y=0}; // Good base center for Mandlebrot
	win->plan.center = (struct s_center){.x=-0.735, .y=-0.24}; // Good zoom center for Mandlebrot
	win->plan.y_max = win->plan.x_max
		/ ((double)settings.width / (double)settings.height);
	win->fractal = settings.fractal;
	win->c = (t_cnb){.real=0, .imag=0};
	if (win->fractal == Julia)
		win->c = settings.c;
	return (win);
}

void	destroy_curr_img(t_window *win)
{
	if (win->img)
	{
		mlx_destroy_image(win->mlx, win->img->img);
		free(win->img);
	}
}

void	put_image_to_window(t_image *img, t_window *win)
{
	destroy_curr_img(win);
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	win->img = img;
}
