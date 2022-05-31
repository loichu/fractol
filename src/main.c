/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/31 21:39:46 by loichu           ###   ########.fr       */
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
	ft_putendl_fd("\t* -0.7+0.2705i", 1);
	ft_putendl_fd("\t* -1.037+0.17i", 1);
	ft_putendl_fd("\t* -0.52+0.57i", 1);
	ft_putendl_fd("\t* 0.295+0.55i", 1);
	ft_putendl_fd("\t* -0.624+0.435i", 1);
	ft_putendl_fd("\nOptions:", 1);
	ft_putendl_fd("\t-res r\t\tdefault: 1920x1080", 1);
	if (settings)
		free(settings);
	exit(1);
}

//double	ft_atof(char *nb)
//{
//	//bool	is_neg;
//	double	res;
//	//double	dec;
//	char	**split;
//	int		i;
//
//	printf("debug atof\n");
//	split = ft_split(nb, '.');
//	res = ft_atoi(*split++);
//	if(*split && ft_isdigit(**split))
//	{
//		i = 0;
//		while(ft_isdigit((*split)[i]))
//			i++;
//		res += ft_atoi(*split) / (10 * i); 
//	}
//	free(--split);
//	printf("%f\n", res);
//	return (res);
//}

//t_cnb	parse_julia_c(char *c)
//{
//	char	**split;
//	t_cnb	cnb;
//
//	split = ft_split(c, '+');
//	printf("real part: %s\n", *split);
//	cnb.real = ft_atof(*split++);
//	printf("real part: %f\n", cnb.real);
//	if (*split)
//		cnb.imag = ft_atof(*split);
//	else
//		cnb.imag = 0;
//	return (cnb);
//}

t_settings	*parse_args(int nb_args, char **args)
{
	t_settings	*settings;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (nb_args < 1)
		print_usage_and_exit(NULL);
	if (!ft_strncmp(*args, "Mandlebrot", ft_strlen(*args)))
		settings->fractal = Mandlebrot;
	else if (!ft_strncmp(*args, "Julia", ft_strlen(*args)))
		settings->fractal = Julia;
	else
		print_usage_and_exit(settings);
	if (settings->fractal == Julia && nb_args > 1)
		settings->c = ft_atoc(*(++args));
	else
		settings->c = (t_cnb){.real=0, .imag=0};
	printf("c = %f + %fi\n", settings->c.real, settings->c.imag);
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
	else
		exit(1);
	put_image_to_window(img, win);
	mlx_loop(win->mlx);
	free(img);
	return (0);
}
