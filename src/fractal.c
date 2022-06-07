/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:14:08 by lhumbert          #+#    #+#             */
/*   Updated: 2022/06/07 17:53:32 by lhumbert         ###   ########.fr       */
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
	if (zoom < 500)
		return (64 + 0.75 * zoom);
	return (512);
}

int	get_pixel_color(int nb_iter, int iter_max)
{
	int	color;

	if (nb_iter == iter_max)
		return (0x00000000);
	color = (nb_iter << 21) + (nb_iter << 10) + nb_iter * 8;
	color &= 0x00FFFFFF;
	return (color);
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
	while (real2 + imag2 < 4 && ++i < iter_max)
	{
		next_z.real = real2 - imag2 + c.real;
		next_z.imag = 2 * z.real * z.imag + c.imag;
		z = next_z;
		real2 = z.real * z.real;
		imag2 = z.imag * z.imag;
	}
	return (i);
}
