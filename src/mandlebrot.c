/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:19:02 by loichu            #+#    #+#             */
/*   Updated: 2022/06/07 17:30:06 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandlebrot(t_image *img, t_cplan plan)
{
	int		i;
	t_pnt	pxl;
	t_cnb	z;
	t_cnb	c;
	int		iter_max;

	iter_max = get_max_iter(plan.zoom);
	pxl = (t_pnt){.x = -1, .y = -1};
	while (++(pxl.x) < img->width)
	{
		while (++(pxl.y) < img->height)
		{
			z = (t_cnb){.real = 0, .imag = 0};
			c = proj_cplx_plan(pxl, plan, img);
			i = get_nb_iter(z, c, iter_max);
			pixel_put(img, pxl.x, pxl.y, get_pixel_color(i, iter_max));
		}
		pxl.y = -1;
	}
}
