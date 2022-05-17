/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:16:09 by loichu            #+#    #+#             */
/*   Updated: 2022/05/17 16:15:01 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_window	*init_window(int width, int height, int bg_color, char *title)
{
	t_window	*img;
	t_pnt		orig;
	
	img = (t_window *)malloc(sizeof(t_window));
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, width, height, title);
	img->img = mlx_new_image(img->mlx, width, height);
	img->addr = mlx_get_data_addr(
			img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	orig.x = 0;
	orig.y = 0;
	draw_rectangle(img, orig, width, height, bg_color);
	return (img);
}
