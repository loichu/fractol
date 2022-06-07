/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/06/07 18:01:01 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
		settings.c = (t_cnb){.real = 0, .imag = 0};
	settings.title = "Fract'ol - Mandlebrot";
	if (settings.fractal == Julia)
		settings.title = "Fract'ol - Julia";
	settings.width = 720;
	settings.height = 720;
	return (settings);
}

int	terminate(t_window *win)
{
	destroy_curr_img(win);
	mlx_destroy_window(win->mlx, win->win);
	free(win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_settings	settings;
	t_window	*win;
	t_image		*img;

	settings = parse_args(argc - 1, &(argv[1]));
	win = init_window(settings);
	img = init_image(win);
	mlx_hook(win->win, 2, 1L << 0, handle_keydown, win);
	mlx_hook(win->win, 17, 0L, handle_close, win);
	mlx_mouse_hook(win->win, handle_mouse, win);
	if (settings.fractal == Mandlebrot)
		draw_mandlebrot(img, win->plan);
	else
		draw_julia(img, win->plan, settings.c);
	put_image_to_window(img, win);
	mlx_loop(win->mlx);
	return (terminate(win));
}
