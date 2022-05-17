/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/17 16:15:26 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(void)
{
	t_window	*img;

	img = init_window(1920, 1080, 0x00FFFFFF, "Fract'ol");
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
	return (0);
}
