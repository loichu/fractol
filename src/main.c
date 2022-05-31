/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/31 16:57:07 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <unistd.h>

void	print_usage_and_exit(t_settings *settings)
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
	if (settings)
		free(settings);
	exit(1);
}

t_settings	*parse_args(int nb_args, char **args)
{
	t_settings	*settings;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (nb_args < 1)
		print_usage_and_exit(NULL);
	while (nb_args--)
	{
		if (!ft_strncmp(*args, "Mandlebrot", ft_strlen(*args)))
			settings->fractal = Mandlebrot;
		else if (!ft_strncmp(*args, "Julia", ft_strlen(*args)))
			settings->fractal = Julia;
		else
			print_usage_and_exit(settings);
		printf("%s\n", (*args)++);
	}
	return (settings);
}

int	main(int argc, char **argv)
{
	t_settings	*settings;
	t_window	*win;
	t_image		*img;

	settings = parse_args(argc - 1, &(argv[1]));
	printf("init window\n");
	win = init_window(1920, 1080, "Fract'ol");
	img = init_image(win, 0x000000FF);
	if (settings->fractal == Mandlebrot)
		draw_mandlebrot(img);
	put_image_to_window(img, win);
	mlx_loop(win->mlx);
	free(img);
	return (0);
}
