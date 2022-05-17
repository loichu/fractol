/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:22:42 by loichu            #+#    #+#             */
/*   Updated: 2022/05/17 16:15:43 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_rectangle(t_window *data, t_pnt orig, int wid, int hgt, int color)
{
	int	i;
	int	j;

	i = orig.y - 1;
	j = 0;
	while (i++ < wid + orig.y - 1)
	{
		j = orig.x - 1;
		while (j++ < hgt + orig.x - 1)
			pixel_put(data, i, j, color);
	}
	printf("(%i;%i)\n", j - 1, i - 1);
}

void	draw_square(t_window *data, t_pnt orig, int size, int color)
{
	draw_rectangle(data, orig, size, size, color);
}
