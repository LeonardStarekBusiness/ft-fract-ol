/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lennert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:33:12 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/21 18:33:13 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterations_lennert(t_complex c, t_complex z, int exp, int depth)
{
	int		i;

	if (ft_isnan(c.real) || ft_isnan(c.i))
		return (-1);
	i = 0;
	while (i < depth)
	{
		if (((z.real * z.real) + (z.i * z.i)) > 4.0)
			return (i);
		if (exp == 2)
			z = add_imag(sq_imag(c_abs(z)), c);
		else
			z = add_imag(pow_imag(c_abs(z), exp), c);
		i++;
	}
	return (-1);
}

void	draw_lennert(t_window *win, t_coord pixel)
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
			iter = iterations_lennert(win->z, c, win->exp, win->depth);
			ft_put_pixel(win, pixel, iter);
			c.i -= increment;
			pixel.y += (int)(1 + win->needs_redraw);
		}
		c.real += increment;
		pixel.x += (int)(1 + win->needs_redraw);
	}
}
