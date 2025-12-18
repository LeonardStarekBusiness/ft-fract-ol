/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:55:01 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/17 17:55:03 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	window_exit(void *data)
{
	t_window	*window;

	window = (t_window *)data;
	if (!window)
		exit(0);

	if (window->img)
		mlx_destroy_image(window->mlx, window->img);
	if (window->window)
		mlx_destroy_window(window->mlx, window->window);
	if (window->mlx)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
	free(window);
	exit(0);
	return (0);
}

void	make_window(int julia, t_complex Z)
{
	t_window	*win;
	char		*title;

	win = malloc(sizeof(t_window));
	if (!win)
		return ;
	win->mlx = mlx_init();
	if (julia)
		title = "JULIA SET";
	else
		title = "MANDELBROT SET";
	win->window = mlx_new_window(win->mlx, WIDTH, HEIGHT, title);

	win->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->addr = mlx_get_data_addr(
		win->img,
		&win->bpp,
		&win->line_len,
		&win->endian
	);
	if (julia)
		draw_julia(win, Z);
	else
	{
		(void)Z;
		draw_mandel(win);
	}
	mlx_hook(win->window, 17, 1L << 17, window_exit, win);
	mlx_loop(win->mlx);
}


void	put_pixel(t_window *win, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

