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

void	ft_put_pixel(t_window *win, t_coord pixel, int iter)
{
	win->addr[pixel.y * (win->line_len / 4) + pixel.x]
		= colorscheme(iter, win->scheme);
	if (win->needs_redraw)
	{
		win->addr[pixel.y * (win->line_len / 4) + (pixel.x + 1)]
			= colorscheme(iter, win->scheme);
		win->addr[(pixel.y + 1) * (win->line_len / 4) + pixel.x]
			= colorscheme(iter, win->scheme);
		win->addr[(pixel.y + 1) * (win->line_len / 4) + (pixel.x + 1)]
			= colorscheme(iter, win->scheme);
	}
}

int	window_exit(void *data)
{
	t_window	*window;

	window = (t_window *)data;
	if (!window)
		exit(0);
	if (window->img)
		mlx_destroy_image(window->mlx, window->img);
	if (window->type)
		free(window->type);
	if (window->window)
		mlx_destroy_window(window->mlx, window->window);
	if (window->mlx)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
	exit(0);
	return (0);
}

int	key_hook(int key, void *data)
{
	t_window	*win;

	win = data;
	win->current_render = now_ms();
	win->last_render = win->current_render;
	if (key == KEY_C)
		win->scheme = (win->scheme + 1) % 5;
	else if (key == ARROW_LEFT)
		win->topleft.real -= (double)win->size / 10.0;
	else if (key == ARROW_RIGHT)
		win->topleft.real += (double)win->size / 10.0;
	else if (key == ARROW_UP)
		win->topleft.i += (double)win->size / 10.0;
	else if (key == ARROW_DOWN)
		win->topleft.i -= (double)win->size / 10.0;
	else if (key == 65307)
	{
		window_exit(win);
		return (0);
	}
	draw_fractal(win);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *data)
{
	t_window	*win;

	win = data;
	win->current_render = now_ms();
	win->last_render = win->current_render;
	(void)x;
	(void)y;
	if (button == 4)
	{
		win->size /= 1.2;
		win->topleft.real += (double)win->size / 10.0;
		win->topleft.i += (double)win->size / 10.0;
	}
	else if (button == 5)
	{
		win->size *= 1.2;
		win->topleft.real -= (double)win->size / 12.0;
		win->topleft.i -= (double)win->size / 12.0;
	}
	draw_fractal(win);
	return (0);
}

void	make_window(t_window *win)
{
	win->mlx = mlx_init();
	win->needs_redraw = 0;
	win->current_render = now_ms();
	win->last_render = now_ms();
	win->window = mlx_new_window(win->mlx, WIN_SIZE,
			WIN_SIZE, win->type);
	win->img = mlx_new_image(win->mlx, WIN_SIZE, WIN_SIZE);
	win->addr = (int *)mlx_get_data_addr(win->img,
			&win->bpp,
			&win->line_len,
			&win->endian);
	mlx_hook(win->window, 17, 1L << 17, window_exit, win);
	mlx_hook(win->window, 12, 1L << 15, draw_fractal, win);
	mlx_hook(win->window, 2, 1L << 0, key_hook, win);
	mlx_hook(win->window, 4, 1L << 2, mouse_hook, win);
	mlx_loop_hook(win->mlx, redraw, win);
	mlx_loop(win->mlx);
}
