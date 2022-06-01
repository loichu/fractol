/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:58:43 by loichu            #+#    #+#             */
/*   Updated: 2022/06/01 17:16:37 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_julia(t_image *img, t_cplan plan, t_cnb c)
{
	//int			w;
	//int			h;
	//int			x;
	//int			y;
	t_pnt		pxl;
	int			i;
	double		tmp;
	int			max_iter;
	t_cnb		z;

	//w = 1920;
	//h = 1080;
	max_iter = 255;
	pxl = (t_pnt){.x=-1, .y=-1};
	while (++(pxl.x) < img->width)
	{
		pxl.y = -1;
		while (++(pxl.y) < img->height)
		{
			z = proj_cplx_plan(pxl, plan, img);
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
