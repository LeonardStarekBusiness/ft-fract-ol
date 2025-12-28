/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:16:12 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/19 16:27:24 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	redraw(t_window *win)
{
	if (!win->needs_redraw)
		return (0);
	win->current_render = now_ms();
	if ((win->current_render - win->last_render) > REDRAW_MS)
	{
		win->needs_redraw = 0;
		draw_fractal(win);
	}
	return (0);
}

int	draw_fractal(t_window *win)
{
	if (!((win->current_render - win->last_render) > REDRAW_MS))
		win->needs_redraw = 1;
	win->depth = (int)((double)ITERATIONS * (depth_level(win->size)));
	if (ft_strncmp("julia", win->type, 5) == 0)
		draw_julia(win, (t_coord){0, 0});
	else if (ft_strncmp("ship", win->type, 5) == 0)
		draw_burning_ship(win, (t_coord){0, 0});
	else if (ft_strncmp("multi", win->type, 5) == 0)
		draw_multi(win, (t_coord){0, 0});
	else
		draw_mandel(win, (t_coord){0, 0});
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
	if (!((win->current_render - win->last_render) > 200))
		redraw(win);
	return (0);
}

void	initialise(char *type, t_complex z, int exp)
{
	t_window	win;

	win.scheme = 0;
	win.topleft.real = -2.5;
	win.topleft.i = -2.5;
	win.size = 5.0;
	win.type = ft_strdup(type);
	win.z = z;
	win.exp = exp;
	win.current_render = now_ms();
	make_window(&win);
}


int	main(int ac, char **av)
{
	t_complex	z;

	z.real = 0;
	z.i = 0;
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0
		&& ft_strlen(av[1]) == 10)
		initialise("mandelbrot", z, 2);
	else if (ac == 2 && ft_strncmp(av[1], "ship", 4) == 0
		&& ft_strlen(av[1]) == 4)
		initialise("ship", z, 2);
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0
		&& ft_strlen(av[1]) == 5)
	{
		z.real = ft_strtof(av[2]);
		z.i = ft_strtof(av[3]);
		if (!ft_isnan(z.real) && !ft_isnan(z.i))
			initialise("julia", z, 2);
		else
			throw_message();
	}
	else if (ac == 3 && ft_strncmp(av[1], "multi", 5) == 0
		&& ft_strlen(av[1]) == 5)
	{
		if (ft_atoi(av[2]) > 0)
			initialise("multi", z, ft_atoi(av[2]));
		else
			throw_message();
	}
	else
		throw_message();
}
