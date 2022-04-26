/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:49:49 by loichu            #+#    #+#             */
/*   Updated: 2022/04/26 17:29:41 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_circle_oct(t_window *data, int xc, int yc, int x, int y, int color)
{
	pixel_put(data, xc+x, yc+y, color);
	pixel_put(data, xc-x, yc+y, color);
	pixel_put(data, xc+x, yc-y, color);
	pixel_put(data, xc-x, yc-y, color);
	pixel_put(data, xc+y, yc+x, color);
	pixel_put(data, xc-y, yc+x, color);
	pixel_put(data, xc+y, yc-x, color);
	pixel_put(data, xc-y, yc-x, color);
}

void	draw_circle(t_window *data, int xc, int yc, int r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - 2 * r;
	draw_circle_oct(data, xc, yc, x, y, color);
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
		draw_circle_oct(data, xc, yc, x, y, color);
	}
}
