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

void	ft_put_pixel(t_window *win, t_coord pixel, int iter)
{
	win->addr[pixel.y * (win->line_len / 4) + pixel.x] = colorscheme(iter, win->scheme, win->needs_redraw);
	if (win->needs_redraw)
	{
			win->addr[pixel.y * (win->line_len / 4) + (pixel.x + 1)] = colorscheme(iter, win->scheme, win->needs_redraw);
			win->addr[(pixel.y + 1) * (win->line_len / 4) + pixel.x] = colorscheme(iter, win->scheme, win->needs_redraw);
			win->addr[(pixel.y + 1) * (win->line_len / 4) + (pixel.x + 1)] = colorscheme(iter, win->scheme, win->needs_redraw);
	}
}
void	draw_burning_ship(t_window *win, t_coord pixel)
{
	int			iter;
	double		increment;
	double		v_reset;
	t_complex	c;
	t_complex	max;

	c = transform(pixel, win);
	max = transform((t_coord){WIN_SIZE, WIN_SIZE}, win);
	increment = ((1.0 / (double)WIN_SIZE) * win->size) * (1.0 + win->needs_redraw);
	v_reset = transform(pixel, win).i;
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		c.i = v_reset;
		while (pixel.y < WIN_SIZE)
		{
			if (ft_isnan(c.real) || ft_isnan(c.i))
				iter = -1;
			else
				iter = iterations_burning_ship(c, win->depth);
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
	t_complex	max;

	c = transform(pixel, win);
	max = transform((t_coord){WIN_SIZE, WIN_SIZE}, win);
	increment = ((1.0 / (double)WIN_SIZE) * win->size) * (1.0 + win->needs_redraw);
	v_reset = transform(pixel, win).i;
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		c.i = v_reset;
		while (pixel.y < WIN_SIZE)
		{
			if (ft_isnan(c.real) || ft_isnan(c.i))
				iter = -1;
			else
				iter = iterations_mandel(c, win->depth);
			ft_put_pixel(win, pixel, iter);
			c.i -= increment;
			pixel.y += (int)(1 + win->needs_redraw);
		}
		c.real += increment;
		pixel.x += (int)(1 + win->needs_redraw);
	}
}

void	draw_multi(t_window *win, t_coord pixel)
{
	int			iter;
	double		increment;
	double		v_reset;
	t_complex	c;
	t_complex	max;

	c = transform(pixel, win);
	max = transform((t_coord){WIN_SIZE, WIN_SIZE}, win);
	increment = ((1.0 / (double)WIN_SIZE) * win->size) * (1.0 + win->needs_redraw);
	v_reset = transform(pixel, win).i;
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		c.i = v_reset;
		while (pixel.y < WIN_SIZE)
		{
			if (ft_isnan(c.real) || ft_isnan(c.i))
				iter = -1;
			else
				iter = iterations_multi(c, win->exp, win->depth);
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
	t_complex	max;

	c = transform(pixel, win);
	max = transform((t_coord){WIN_SIZE, WIN_SIZE}, win);
	increment = ((1.0 / (double)WIN_SIZE) * win->size) * (1.0 + win->needs_redraw);
	v_reset = transform(pixel, win).i;
	while (pixel.x < WIN_SIZE)
	{
		pixel.y = 0;
		c.i = v_reset;
		while (pixel.y < WIN_SIZE)
		{
			if (ft_isnan(c.real) || ft_isnan(c.i))
				iter = -1;
			else
				iter = iterations_julia(win->z, c, win->depth);
			ft_put_pixel(win, pixel, iter);
			c.i -= increment;
			pixel.y += (int)(1 + win->needs_redraw);
		}
		c.real += increment;
		pixel.x += (int)(1 + win->needs_redraw);
	}
}
