/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:14:08 by lhumbert          #+#    #+#             */
/*   Updated: 2022/06/02 11:26:55 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_cnb	proj_cplx_plan(t_pnt pxl, t_cplan plan, t_image *img)
{
	t_cnb	res;
	double	half_w;
	double	half_h;

	half_w = img->width / 2;
	half_h = img->height / 2;
	res.real = (plan.x_max * ((double)pxl.x - half_w) / half_w) / plan.zoom
		+ plan.center.x;
	res.imag = (plan.y_max * ((double)pxl.y - half_h) / half_h) / plan.zoom
		+ plan.center.y;
	return (res);
}
