/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:28:25 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/25 15:28:26 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isnan(double fp)
{
	return (fp != fp);
}

double	ft_pow(double x, double y)
{
	while (y > 0)
	{
		x *= x;
		y--;
	}
	return (x);
}

double	depth_level(double size)
{
	double	i;

	i = 1.0;
	while (size < 1.0)
	{
		size *= 40.0;
		i += 0.2;
	}
	return (i);
}

t_complex	transform(t_coord pixel, t_window *win)
{
	t_complex		fpoint;

	fpoint.real = (((double)pixel.x / (double)WIN_SIZE) * win->size) + win->topleft.real;
	fpoint.i = (((double)(800 - pixel.y) / (double)WIN_SIZE) * win->size) + win->topleft.i;
	return (fpoint);
}
