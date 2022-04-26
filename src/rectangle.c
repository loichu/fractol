/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loichu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:22:42 by loichu            #+#    #+#             */
/*   Updated: 2022/04/26 17:30:21 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_square(t_window *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = y - 1;
	j = 0;
	while (i++ < size + y - 1)
	{
		j = x - 1;
		while (j++ < size + x - 1)
			pixel_put(data, j, i, color);
	}
	printf("(%i;%i)\n", j - 1, i - 1);
}
