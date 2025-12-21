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

void	draw_burning_ship(t_window *win)
{
	t_complex	c;
	t_coord		pos;
	int			i;
	double		increment;
	t_complex	max;

	max.i = win->topleft.i + win->size;
	max.real = win->topleft.real + win->size;
	increment = win->size / (WIN_SIZE * 1.1);
	c.i = win->topleft.i;
	while (c.i < max.i)
	{
		c.real = win->topleft.real;
		while (c.real < max.real)
		{
			i = iterations_burning_ship(c);
			pos = transform(c, win->topleft, win->size);
			win->addr[pos.y * WIN_SIZE + pos.x] = colorscheme(i, win->scheme);
			c.real += increment;
		}
		c.i += increment;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

void	draw_mandel(t_window *win)
{
	t_complex	c;
	t_coord		pos;
	int			i;
	double		increment;
	t_complex	max;

	max.i = win->topleft.i + win->size;
	max.real = win->topleft.real + win->size;
	increment = win->size / (WIN_SIZE * 1.1);
	c.i = win->topleft.i;
	while (c.i < max.i)
	{
		c.real = win->topleft.real;
		while (c.real < max.real)
		{
			i = iterations_mandel(c);
			pos = transform(c, win->topleft, win->size);
			win->addr[pos.y * WIN_SIZE + pos.x] = colorscheme(i, win->scheme);
			c.real += increment;
		}
		c.i += increment;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

void	draw_julia(t_window *win)
{
	t_complex	c;
	t_coord		pos;
	int			i;
	double		increment;
	t_complex	max;

	max.i = win->topleft.i + win->size;
	max.real = win->topleft.real + win->size;
	increment = win->size / (WIN_SIZE * 1.1);
	c.i = win->topleft.i;
	while (c.i < max.i)
	{
		c.real = win->topleft.real;
		while (c.real < max.real)
		{
			i = iterations_julia(win->z, c);
			pos = transform(c, win->topleft, win->size);
			win->addr[pos.y * WIN_SIZE + pos.x] = colorscheme(i, win->scheme);
			c.real += increment;
		}
		c.i += increment;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

void	initialise(char *type, t_complex z)
{
	t_window	win;

	win.scheme = 0;
	win.topleft.real = -2.5;
	win.topleft.i = -2.5;
	win.size = 5.0;
	win.type = ft_strdup(type);
	win.z = z;
	make_window(&win);
}

int	main(int ac, char **av)
{
	t_complex	z;

	z.real = 0;
	z.i = 0;
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0
		&& ft_strlen(av[1]) == 10)
		initialise("mandelbrot", z);
	else if (ac == 2 && ft_strncmp(av[1], "ship", 4) == 0
		&& ft_strlen(av[1]) == 4)
		initialise("ship", z);
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0
		&& ft_strlen(av[1]) == 5)
	{
		z.real = ft_strtof(av[2]);
		z.i = ft_strtof(av[3]);
		if (!ft_isnan(z.real) && !ft_isnan(z.i))
			initialise("julia", z);
		else
			throw_message();
	}
	else
		throw_message();
}
