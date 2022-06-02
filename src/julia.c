/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:58:43 by loichu            #+#    #+#             */
/*   Updated: 2022/06/02 13:32:15 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_julia(t_image *img, t_cplan plan, t_cnb c)
{
	int		i;
	t_pnt	pxl;
	t_cnb	z;
	int		iter_max;

	iter_max = get_max_iter(plan.zoom);
	pxl = (t_pnt){.x=-1, .y=-1};
	while (++(pxl.x) < img->width)
	{
		while (++(pxl.y) < img->height)
		{
			z = proj_cplx_plan(pxl, plan, img);
			i = get_nb_iter(z, c, iter_max);
			pixel_put(img, pxl.x, pxl.y, (i << 21) + (i << 10) + i*8);
		}
		pxl.y = -1;
	}
}
