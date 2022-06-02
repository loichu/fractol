/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:19:02 by loichu            #+#    #+#             */
/*   Updated: 2022/06/02 10:16:44 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandlebrot(t_image *img, t_cplan plan)
{
	int			i;
	double		tmp;
	int			max_iter;
	t_pnt		pxl;
	t_cnb		z;
	t_cnb		c;

	max_iter = 255;
	pxl = (t_pnt){.x=-1, .y=-1};
	while (++(pxl.x) < img->width)
	{
		pxl.y = -1;
		while (++(pxl.y) < img->height)
		{
			c = proj_cplx_plan(pxl, plan, img);
			z = (t_cnb){.real = 0, .imag = 0};
			i = max_iter;
			while (pow2(z.real) + pow2(z.imag) < 4 && i > 1)
			{
				tmp = pow2(z.real) - pow2(z.imag) + c.real;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = tmp;
				i--;
			}
			pixel_put(img, pxl.x, pxl.y, (i << 21) + (i << 10) + i*8);
		}
	}
}
