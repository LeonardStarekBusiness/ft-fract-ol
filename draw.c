/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:40:31 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/26 19:40:32 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burning_ship(t_window *win, t_coord pixel)
{
	int			iter;
	double		increment;
	double		v_reset;
	t_complex	c;

	c = transform(pixel, win);
	increment = ((1.0 / (double)WIN_SIZE) * win->size)
		* (1.0 + win->needs_redraw);
	v_reset = transform(pixel, win).i;
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		c.i = v_reset;
		while (pixel.y < WIN_SIZE)
		{
			iter = iterations_burning_ship(c, win->exp, win->depth);
			ft_put_pixel(win, pixel, iter);
			c.i -= increment;
			pixel.y += (int)(1 + win->needs_redraw);
		}
		c.real += increment;
		pixel.x += (int)(1 + win->needs_redraw);
	}
}

void	draw_mandel(t_window *win, t_coord pixel)
{
	int			iter;
	double		increment;
	double		v_reset;
	t_complex	c;

	c = transform(pixel, win);
	increment = ((1.0 / (double)WIN_SIZE) * win->size)
		* (1.0 + win->needs_redraw);
	v_reset = transform(pixel, win).i;
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		c.i = v_reset;
		while (pixel.y < WIN_SIZE)
		{
			iter = iterations_mandel(c, win->exp, win->depth);
			ft_put_pixel(win, pixel, iter);
			c.i -= increment;
			pixel.y += (int)(1 + win->needs_redraw);
		}
		c.real += increment;
		pixel.x += (int)(1 + win->needs_redraw);
	}
}

void	draw_julia(t_window *win, t_coord pixel)
{
	int			iter;
	double		increment;
	double		v_reset;
	t_complex	c;

	c = transform(pixel, win);
	increment = ((1.0 / (double)WIN_SIZE) * win->size)
		* (1.0 + win->needs_redraw);
	v_reset = transform(pixel, win).i;
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		c.i = v_reset;
		while (pixel.y < WIN_SIZE)
		{
			iter = iterations_julia(win->z, c, win->exp, win->depth);
			ft_put_pixel(win, pixel, iter);
			c.i -= increment;
			pixel.y += (int)(1 + win->needs_redraw);
		}
		c.real += increment;
		pixel.x += (int)(1 + win->needs_redraw);
	}
}
