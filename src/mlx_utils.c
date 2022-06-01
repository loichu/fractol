/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:16:09 by loichu            #+#    #+#             */
/*   Updated: 2022/06/01 14:36:10 by lhumbert         ###   ########.fr       */
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
