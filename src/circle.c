/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:49:49 by loichu            #+#    #+#             */
/*   Updated: 2022/05/31 16:22:17 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_circle_oct(t_image *img, int xc, int yc, int x, int y, int color)
{
	pixel_put(img, xc+x, yc+y, color);
	pixel_put(img, xc-x, yc+y, color);
	pixel_put(img, xc+x, yc-y, color);
	pixel_put(img, xc-x, yc-y, color);
	pixel_put(img, xc+y, yc+x, color);
	pixel_put(img, xc-y, yc+x, color);
	pixel_put(img, xc+y, yc-x, color);
	pixel_put(img, xc-y, yc-x, color);
}

void	draw_circle(t_image *img, int xc, int yc, int r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - 2 * r;
	draw_circle_oct(img, xc, yc, x, y, color);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		draw_circle_oct(img, xc, yc, x, y, color);
	}
}
