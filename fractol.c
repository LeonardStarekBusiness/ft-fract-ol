/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:16:12 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/18 15:25:34 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int	iterations_mandel(t_complex c)
{
	int			i;
	t_complex	z;

	i = 0;
	z.real = 0;
	z.i = 0;
	while (i < ITERATIONS)
	{
		if (((z.real * z.real) + (z.i * z.i)) > 4)
			return (i);
		z = add_imag(sq_imag(z), c);
		i++;
	}
	return (-1);
}

int	iterations_julia(t_complex c, t_complex z)
{
	int		i;

	i = 0;
	while (i < ITERATIONS)
	{
		if (((z.real * z.real) + (z.i * z.i)) > 4)
			return (i);
		z = add_imag(sq_imag(z), c);
		i++;
	}
	return (-1);
}

void	draw_mandel(t_window *win)
{
	t_complex	c;
	t_complex	topleft;
	double		size;
	t_coord		pos;
	int			i;

	topleft.real = -2.5;
	topleft.i = -2.5;
	size = 5.0;
	c.i = -2.5;
	while (c.i < topleft.i + size)
	{
		c.real = -2.5;
		while (c.real < (topleft.real + size))
		{
			i = iterations_mandel(c);
			pos = transform(c, topleft, size);
			put_pixel(win, pos.x, pos.y, colorscheme(i));
			c.real += 0.005;
		}
		c.i += 0.005;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

void	draw_julia(t_window *win, t_complex Z)
{
	t_complex	c;
	t_complex	topleft;
	double		size;
	t_coord		pos;
	int			i;

	topleft.real = -2.5;
	topleft.i = -2.5;
	size = 5.0;
	c.i = -2.5;
	while (c.i < topleft.i + size)
	{
		c.real = -2.5;
		while (c.real < (topleft.real + size))
		{
			i = iterations_julia(Z, c);
			pos = transform(c, topleft, size);
			put_pixel(win, pos.x, pos.y, colorscheme(i));
			c.real += 0.005;
		}
		c.i += 0.005;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_complex	z;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0
		&& ft_strlen(av[1]) == 10)
	{
		z.real = 0;
		z.i = 0;
		make_window(0, z);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0
		&& ft_strlen(av[1]) == 5)
	{
		z.real = strtof(av[2], NULL);
		z.i = strtof(av[3], NULL);
		make_window(1, z);
	}
	else
	{
		ft_putstr_fd("+-----------------------------------------------------------+\n", 1);
		ft_putstr_fd("Proper usage: ./fractol <mandelbrot/julia> <real> <imaginary>\n", 1);
		ft_putstr_fd("+-----------------------------------------------------------+\n", 1);
	}
}
