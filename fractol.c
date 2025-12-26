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

int	draw_fractal(t_window *win)
{
	int		fractal;
	t_coord		pixel;

	fractal = 0;
	if (ft_strncmp("julia", win->type, 5) == 0)
		fractal = 1;
	else if (ft_strncmp("ship", win->type, 5) == 0)
		fractal = 2;
	else if (ft_strncmp("multi", win->type, 5) == 0)
		fractal = 3;
	pixel.x = 0;
	win->depth = (int)((double)ITERATIONS * (depth_level(win->size)));
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		while (pixel.y < WIN_SIZE)
		{
			if (fractal == 1)
				draw_julia(win, pixel);
			else if (fractal == 2)
				draw_burning_ship(win, pixel);
			else if (fractal == 3)
				draw_multi(win, pixel);
			else
				draw_mandel(win, pixel);
			pixel.y++;
		}
		pixel.x++;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
	return (0);
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
