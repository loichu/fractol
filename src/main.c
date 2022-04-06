/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2022/04/06 19:39:19 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (i++ < size + y - 1)
	{
		j = x - 1;
		while (j++ < size + x - 1)
			my_mlx_pixel_put(data, j, i, color);
	}
	printf("(%i;%i)\n", j - 1, i - 1);
}

void	draw_circle_oct(t_data *data, int xc, int yc, int x, int y, int color)
{
	my_mlx_pixel_put(data, xc+x, yc+y, color);
	my_mlx_pixel_put(data, xc-x, yc+y, color);
	my_mlx_pixel_put(data, xc+x, yc-y, color);
	my_mlx_pixel_put(data, xc-x, yc-y, color);
	my_mlx_pixel_put(data, xc+y, yc+x, color);
	my_mlx_pixel_put(data, xc-y, yc+x, color);
	my_mlx_pixel_put(data, xc+y, yc-x, color);
	my_mlx_pixel_put(data, xc-y, yc-x, color);
}

void	draw_circle(t_data *data, int xc, int yc, int r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - 2 * r;
	draw_circle_oct(data, xc, yc, x, y, color);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		draw_circle_oct(data, xc, yc, x, y, color);
	}
}	

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	printf("floor 4,2: %f\n", floor(4.2));


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//draw_square(&img, 0, 0, 500, 0x00FF0000);
	//draw_square(&img, 500, 0, 250, 0x0000FF00);
	//draw_square(&img, 500, 250, 250, 0x000000FF);
	draw_circle(&img, 500, 500, 250, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
