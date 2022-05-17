/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:58:43 by loichu            #+#    #+#             */
/*   Updated: 2022/05/17 18:30:18 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	pow2(double nb)
{
	return (nb * nb);
}

void	draw_julia(t_window *data, t_cnb c)
{
	int			w;
	int			h;
	int			x;
	int			y;
	int			i;
	double		tmp;
	int			max_iter;
	t_cnb		z;

	w = 1920;
	h = 1080;
	max_iter = 255;
	x = -1;
	while (++x < w)
	{
		y = -1;
		while (++y < h)
		{
			z.real = 1.5*(x - w/2)/(w/2);
			z.imag = 1.0*(y - h/2)/(h/2);
			i = max_iter;
			while (pow2(z.real) + pow2(z.imag) < 4 && i > 1)
			{
				tmp = pow2(z.real) - pow2(z.imag) + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = tmp;
				i--;
			}
			//printf("%i\n", i);
			//printf("pixel %i:%i i: %i color %X\n", x, y, i, (i << 21) + (i << 10) + i*8);
			pixel_put(data, x, y, (i << 21) + (i << 10) + i*8);
		}
	}
}
