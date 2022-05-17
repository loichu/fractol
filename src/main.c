/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/17 16:56:11 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(void)
{
	t_window	*img;

	img = init_window(1920, 1080, 0x00FFFFFF, "Fract'ol");
	printf("init window\n");
	draw_julia(img, (t_cnb) {.real = -0.7, .imag = 0.2705});
	printf("drew julia\n");
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
	free(img);
	return (0);
}
