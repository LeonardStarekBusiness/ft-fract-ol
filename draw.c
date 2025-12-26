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
	int		iter;
	t_complex	c;

	c = transform(pixel, win);
	iter = iterations_burning_ship(c, win->depth);
	win->addr[pixel.y * (win->line_len / 4) + pixel.x] = colorscheme(iter, win->scheme);
}

void	draw_mandel(t_window *win, t_coord pixel)
{
	int		iter;
	t_complex	c;

	c = transform(pixel, win);
	iter = iterations_mandel(c, win->depth);
	win->addr[pixel.y * (win->line_len / 4) + pixel.x] = colorscheme(iter, win->scheme);
}

void	draw_multi(t_window *win, t_coord pixel)
{
	int		iter;
	t_complex	c;

	c = transform(pixel, win);
	iter = iterations_multi(c, win->exp, win->depth);
	win->addr[pixel.y * (win->line_len / 4) + pixel.x] = colorscheme(iter, win->scheme);
}

void	draw_julia(t_window *win, t_coord pixel)
{
	int		iter;
	t_complex	c;

	c = transform(pixel, win);
	iter = iterations_julia(win->z, c, win->depth);
	win->addr[pixel.y * (win->line_len / 4) + pixel.x] = colorscheme(iter, win->scheme);
}
