/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:19:02 by loichu            #+#    #+#             */
/*   Updated: 2022/06/03 17:40:27 by lhumbert         ###   ########.fr       */
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
	pxl = (t_pnt){.x=-1, .y=-1};
	while (++(pxl.x) < img->width)
	{
		while (++(pxl.y) < img->height)
		{
			z = (t_cnb){.real = 0, .imag = 0};
			//printf("debug\n");
			c = proj_cplx_plan(pxl, plan, img);
			//printf("project c in complex plan\n");
			i = get_nb_iter(z, c, iter_max);
			pixel_put(img, pxl.x, pxl.y, get_pixel_color(i));
		}
		pxl.y = -1;
	}
	//printf("drew mandlebrot\n");
}
