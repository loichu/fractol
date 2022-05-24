/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/24 23:13:17 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <unistd.h>

void	print_usage_and_exit()
{
	ft_putendl_fd("usage: fractol fract [options]", 1);
	ft_putendl_fd("\nfract:\tMandlebrot", 1);
	ft_putendl_fd("\tJulia <C>", 1);
	ft_putendl_fd("\nIntersting C values for Julia:", 1);
	ft_putendl_fd("\t* \"-0.7 + 0.2705i\"", 1);
	ft_putendl_fd("\t* \"-1.037 + 0.17i\"", 1);
	ft_putendl_fd("\t* \"-0.52 + 0.57i\"", 1);
	ft_putendl_fd("\t* \"0.295 + 0.55i\"", 1);
	ft_putendl_fd("\t* \"-0.624 + 0.435i\"", 1);
	ft_putendl_fd("\nOptions:", 1);
	ft_putendl_fd("\t-res r\t\tdefault: 1920x1080", 1);
	exit(1);
}

void	parse_args(int nb_args, char **args)
{
	if (nb_args < 1)
		print_usage_and_exit();

		
	while (nb_args--)
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
	img = init_image(win, 0x000000FF);
	put_image_to_window(img, win);
	img = init_image(win, 0x0000FF00);
	sleep(1);
	put_image_to_window(img, win);
	img = init_image(win, 0x00FF0000);
	sleep(1);
	put_image_to_window(img, win);
	img = init_image(win, 0x00FFFFFF);
	sleep(1);
	draw_julia(img, (t_cnb){.real = -0.7, .imag = 0.2705});
	printf("drew Julia\n");
	put_image_to_window(img, win);
	sleep(5);
	img = init_image(win, 0x00FFFFFF);
	draw_mandlebrot(img);
	put_image_to_window(img, win);
	mlx_loop(win->mlx);
	free(img);
	return (0);
}
