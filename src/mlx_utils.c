/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:16:09 by loichu            #+#    #+#             */
/*   Updated: 2022/05/24 14:34:58 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_image		*init_image(t_window *win, int bg_color)
{
	t_image		*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	img->addr = mlx_get_data_addr(
		img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	draw_rectangle(
		img, (t_pnt) {.x = 0, .y = 0}, win->width, win->height, bg_color);
	return (img);
}

t_window	*init_window(int width, int height, char *title)
{
	t_window	*win;
	
	win = (t_window *)malloc(sizeof(t_window));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, title);
	win->width = width;
	win->height = height;
	win->img = NULL;
	return (win);
}

void	put_image_to_window(t_image *img, t_window *win)
{
	if (win->img)
	{
		mlx_destroy_image(win->mlx, win->img->img);
		free(win->img);
	}
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	win->img = img;
}
