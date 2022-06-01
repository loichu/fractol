/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:19:02 by loichu            #+#    #+#             */
/*   Updated: 2022/06/01 14:35:16 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandlebrot(t_image *img)
{
	int			w;
	int			h;
	int			x;
	int			y;
	int			i;
	double		tmp;
	int			max_iter;
	t_cnb		z;
	t_cnb		c;

	w = 1920;
	h = 1080;
	max_iter = 255;
	x = -1;
	while (++x < w)
	{
		y = -1;
		while (++y < h)
		{
			c.real = 2.5 * (x - w/2)/(w/2);
			c.imag = 2.0 * (y - h/2)/(h/2);
			z = (t_cnb){.real = 0, .imag = 0};
			i = max_iter;
			while (pow2(z.real) + pow2(z.imag) < 4 && i > 1)
			{
				tmp = pow2(z.real) - pow2(z.imag) + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = tmp;
				i--;
			}
			if (x == w/2 || y == h/2)
				pixel_put(img, x, y, 0x00FF0000);
			else
				pixel_put(img, x, y, (i << 21) + (i << 10) + i*8);
		}
	}
}
