/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/06/03 00:11:31 by loichu           ###   ########.fr       */
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

int	terminate(t_window *win)
{
	destroy_curr_img(win);
	mlx_destroy_window(win->mlx, win->win);
	free(win);
	return (0);
}

int	handle_keydown(int key, t_window *win)
{
	//printf("%x\n", key);
	printf("keydown in window %p\n", win);
	if (key == 0xff1b)
		exit(terminate(win));
	return(0);
}

int handle_close(t_window *win)
{
	//printf("close\n");
	exit(terminate(win));
	return (0);
}

int	handle_mouse(int btn, int x, int y, t_window *win)
{
	printf("test\n");
	printf("scroll in window %p\n", win);
	//printf("Fractal: %i\n", win->fractal);
	//printf("c: %f + %fi\n", win->c.real, win->c.imag);
	//printf("zoom: %f\n", win->plan.zoom);
	//if (mouse_code == 4)
	//	win->plan.zoom += 5;
	//if (mouse_code == 5)
	//	win->plan.zoom -= 5;
	//if (win->fractal == Julia)
	//	draw_julia(win->img, win->plan, win->c);
	//else
	//	draw_mandlebrot(win->img, win->plan);
	return(0);
}

int	main(int argc, char **argv)
{
	t_settings	settings;
	t_window	*win;
	t_image		*img;

	settings = parse_args(argc - 1, &(argv[1]));
	win = init_window(settings);
	printf("zoom: %f\n", win->plan.zoom);
	img = init_image(win, settings);
	mlx_hook(win->win, 2, 1L<<0, handle_keydown, win);
	mlx_hook(win->win, 17, 0L, handle_close, win);
	printf("window initialized %p\n", win);
	mlx_hook(win->win, 4, 0L, handle_mouse, win);
	//mlx_mouse_hook(win->win, handle_mouse, win);
	if (settings.fractal == Mandlebrot)
		draw_mandlebrot(img, win->plan);
	else
		draw_julia(img, win->plan, settings.c);
	put_image_to_window(img, win);
	mlx_loop(win->mlx);
	return (terminate(win));
}
