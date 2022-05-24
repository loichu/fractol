/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/24 15:41:35 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <unistd.h>

void	parse_args(int nb_args, char **args)
{
	while(nb_args--)
	{
		printf("%s\n", (*args)++);
	}
}

int	main(int argc, char **argv)
{
	t_window	*win;
	t_image		*img;

	parse_args(argc - 1, &(argv[1]));
	printf("init window\n");
	win = init_window(1920, 1080, "Fract'ol");
	img = init_image(win, 0x00FFFFFF);
	put_image_to_window(img, win);
	sleep(2);
	img = init_image(win, 0x000000FF);
	put_image_to_window(img, win);
	sleep(2);
	img = init_image(win, 0x0000FF00);
	put_image_to_window(img, win);
	sleep(2);
	img = init_image(win, 0x00FF0000);
	put_image_to_window(img, win);
	mlx_loop(win->mlx);
	free(img);
	return (0);
}
