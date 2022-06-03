/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:14:08 by lhumbert          #+#    #+#             */
/*   Updated: 2022/06/03 15:33:44 by lhumbert         ###   ########.fr       */
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

int	get_max_iter(int zoom)
{
	return (256);
	//if (zoom < 300)
	//	return (128 << (int)(zoom / 100));
	//return (1024);
}

int	get_nb_iter(t_cnb z, t_cnb c, int iter_max)
{
	int		i;
	t_cnb	next_z;
	double	real2;
	double	imag2;

	real2 = z.real * z.real;
	imag2 = z.imag * z.imag;
	i = 0;
	while (real2 + imag2 < 4 && i++ < iter_max)
	{
		next_z.real = real2 - imag2 + c.real;
		next_z.imag = 2 * z.real * z.imag + c.imag;
		z = next_z;
		real2 = z.real * z.real;
		imag2 = z.imag * z.imag;
	}
	return (i);
}
