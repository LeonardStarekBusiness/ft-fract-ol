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
	if (!win->needs_redraw || win->size < 0.0000000000003)
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
	if (!((win->current_render - win->last_render) > REDRAW_MS)
		|| win->size < 0.0000000000003)
		win->needs_redraw = 1;
	win->depth = (int)((double)ITERATIONS * (depth_level(win->size)));
	if (ft_strncmp("julia", win->type, 6) == 0)
		draw_julia(win, (t_coord){0, 0});
	else if (ft_strncmp("ship", win->type, 5) == 0)
		draw_burning_ship(win, (t_coord){0, 0});
	else if (ft_strncmp("lennert", win->type, 8) == 0)
		draw_lennert(win, (t_coord){0, 0});
	else
		draw_mandel(win, (t_coord){0, 0});
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
	if (!((win->current_render - win->last_render) > 200))
		redraw(win);
	return (0);
}

void	init(char *type, t_complex z, int exp, char **av)
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
	print_formula(type, exp, av);
	make_window(&win);
}

int	main(int ac, char **av)
{
	t_complex	z;

	if (ac == 2 && !(ft_strncmp(av[1], "lennert", 8)))
		return (init(av[1], (t_complex){-0.8, -0.8}, 13, av), 0);
	else if ((ac > 1 && !(ft_strncmp(av[1], "mandelbrot", 11)))
		|| (ac > 1 && !(ft_strncmp(av[1], "ship", 5))))
	{
		if (ac == 3 && ft_atoi(av[2]) <= 0)
			return (throw_message(), 0);
		else if (ac == 3)
			return (init(av[1], (t_complex){0, 0}, ft_atoi(av[2]), av), 0);
		else if (ac == 2)
			return (init(av[1], (t_complex){0, 0}, 2, av), 0);
	}
	else if (ac > 3 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		z = (t_complex){ft_strtof(av[2]), ft_strtof(av[3])};
		if (ft_isnan(z.real) || ft_isnan(z.i))
			return (throw_message(), 0);
		if (ac == 4)
			return (init("julia", z, 2, av), 0);
		else if (ac == 5)
			return (init("julia", z, ft_atoi(av[4]), av), 0);
	}
	return (throw_message(), 0);
}
