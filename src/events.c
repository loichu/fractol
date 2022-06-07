/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:37:51 by lhumbert          #+#    #+#             */
/*   Updated: 2022/06/07 17:54:19 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_keydown(int key, t_window *win)
{
	t_image	*img;

	if (key == 0x35)
		exit(terminate(win));
	else if (key == 0x7b)
		win->plan.center.x -= 0.5 / win->plan.zoom;
	else if (key == 0x7e)
		win->plan.center.y -= 0.5 / win->plan.zoom;
	else if (key == 0x7d)
		win->plan.center.y += 0.5 / win->plan.zoom;
	else if (key == 0x7c)
		win->plan.center.x += 0.5 / win->plan.zoom;
	else
		return (1);
	img = init_image(win);
	if (win->fractal == Julia)
		draw_julia(img, win->plan, win->c);
	else
		draw_mandlebrot(img, win->plan);
	put_image_to_window(img, win);
	return (0);
}

int	handle_close(t_window *win)
{
	exit(terminate(win));
	return (0);
}

int	handle_mouse(int btn, int x, int y, t_window *win)
{
	t_image	*img;

	x = (int) x;
	y = (int) y;
	if (btn == 5 && win->plan.zoom < 100000)
		win->plan.zoom *= 2;
	else if (btn == 4 && win->plan.zoom > 0.5)
		win->plan.zoom /= 2;
	else
		return (1);
	img = init_image(win);
	if (win->fractal == Julia)
		draw_julia(img, win->plan, win->c);
	else
		draw_mandlebrot(img, win->plan);
	put_image_to_window(img, win);
	return (0);
}
