/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/06/02 12:15:18 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <unistd.h>

void	print_usage_and_exit(void)
{
	ft_putendl_fd("usage: fractol fract [options]", 1);
	ft_putendl_fd("\nfract:\tMandlebrot", 1);
	ft_putendl_fd("\tJulia <C>", 1);
	ft_putendl_fd("\nIntersting C values for Julia:", 1);
	ft_putendl_fd("\t* -0.7+0.2705i", 1);
	ft_putendl_fd("\t* -1.037+0.17i", 1);
	ft_putendl_fd("\t* -0.52+0.57i", 1);
	ft_putendl_fd("\t* 0.295+0.55i", 1);
	ft_putendl_fd("\t* -0.624+0.435i", 1);
	exit(1);
}

t_settings	parse_args(int nb_args, char **args)
{
	t_settings	settings;

	if (nb_args < 1)
		print_usage_and_exit();
	if (!ft_strncmp(*args, "Mandlebrot", ft_strlen(*args)))
		settings.fractal = Mandlebrot;
	else if (!ft_strncmp(*args, "Julia", ft_strlen(*args)))
		settings.fractal = Julia;
	else
		print_usage_and_exit();
	if (settings.fractal == Julia && nb_args > 1)
		settings.c = ft_atoc(*(++args));
	else
		settings.c = (t_cnb){.real=0, .imag=0};
	printf("c = %f + %fi\n", settings.c.real, settings.c.imag);
	settings.title = "Fract'ol - Mandlebrot";
	if (settings.fractal == Julia)
		settings.title = "Fract'ol - Julia";
	settings.width = 1920;
	settings.height = 1080;
	return (settings);
}

int	main(int argc, char **argv)
{
	t_settings	settings;
	t_window	*win;
	t_image		*img;
	t_cplan		cplan;

	settings = parse_args(argc - 1, &(argv[1]));
	cplan.x_max = 2.1;
	cplan.zoom = 300;
	//cplan.center = (struct s_center){.x=-0.6, .y=0}; // Good base center for Mandlebrot
	cplan.center = (struct s_center){.x=-0.735, .y=-0.24}; // Good zoom center for Mandlebrot
	cplan.y_max = cplan.x_max
		/ ((double)settings.width / (double)settings.height);
	win = init_window(settings);
	img = init_image(win, settings);
	if (settings.fractal == Mandlebrot)
		draw_mandlebrot(img, cplan);
	else
		draw_julia(img, cplan, settings.c);
	put_image_to_window(img, win);
	mlx_loop(win->mlx);
	free(img);
	return (0);
}
