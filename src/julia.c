/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:58:43 by loichu            #+#    #+#             */
/*   Updated: 2022/05/24 22:54:08 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_julia(t_image *img, t_cnb c)
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
			//printf("Will put pixel");
			pixel_put(img, x, y, (i << 21) + (i << 10) + i*8);
			//printf("%i %i\n", x, y);
		}
	}
	printf("(%i;%i)\n", w, h);
}
