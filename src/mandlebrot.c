/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:19:02 by loichu            #+#    #+#             */
/*   Updated: 2022/05/17 23:49:18 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandlebrot(t_window *data)
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
	//c = (t_cnb){.real = -1.5, .imag = 
	max_iter = 255;
	x = -1;
	while (++x < w)
	{
		y = -1;
		while (++y < h)
		{
			c.real = 1.5*(x - w/2)/(w/2);
			c.imag = 1.0*(y - h/2)/(h/2);
			z = (t_cnb){.real = 0, .imag = 0};
			i = max_iter;
			while (pow2(z.real) + pow2(z.imag) < 4 && i > 1)
			{
				tmp = pow2(z.real) - pow2(z.imag) + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = tmp;
				i--;
			}
			pixel_put(data, x, y, (i << 21) + (i << 10) + i*8);
		}
	}
}
