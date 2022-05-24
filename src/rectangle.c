/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:22:42 by loichu            #+#    #+#             */
/*   Updated: 2022/05/24 22:57:57 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_rectangle(t_image *img, t_pnt orig, int wid, int hgt, int color)
{
	int	i;
	int	j;

	i = orig.y - 1;
	j = 0;
	while (i++ < wid + orig.y - 1)
	{
		j = orig.x - 1;
		while (j++ < hgt + orig.x - 1)
			pixel_put(img, i, j, color);
	}
	printf("(%i;%i)\n", i, j);
}

void	draw_square(t_image *img, t_pnt orig, int size, int color)
{
	draw_rectangle(img, orig, size, size, color);
}
