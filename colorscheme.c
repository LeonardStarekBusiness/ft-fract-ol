/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorscheme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:19:05 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/18 14:19:07 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_lava(int color)
{
	return ((255 << 16) | ((165 * (10 - color) / 9) << 8));
}

int	color_ice(int c)
{
	int	r;
	int	g;
	int	b;

	if (c < 0)
		c = 0;
	if (c > 25)
		c = 25;
	r = 173 - (173 * c / 25);
	g = 216 - (216 * c / 25);
	b = 230 + (25 * c / 25);
	return ((r << 16) | (g << 8) | b);
}

int	color_purple(int c)
{
	int	r;
	int	g;
	int	b;

	if (c < 0)
		c = 0;
	if (c > 25)
		c = 25;
	r = 255 - (127 * c / 25);
	g = 105 - (105 * c / 25);
	b = 180 - (52 * c / 25);
	return ((r << 16) | (g << 8) | b);
}

int	color_neon(int color)
{
	if (color == -1)
		return (0x0039FF14);
	else
		return ((color * 4096) % 2147483647);
}

int	colorscheme(int color, int scheme)
{
	if (scheme == 1)
	{
		if (color == -1)
			return (0x002e293a);
		else
			return (color_lava(color));
	}
	else if (scheme == 2)
	{
		if (color == -1)
			return (0x00DDDDDD);
		else
			return (color_ice(color));
	}
	else if (scheme == 3)
	{
		if (color == -1)
			return (0x00ff007f);
		else
			return (color_purple(color));
	}
	else if (scheme == 4)
		return (color_neon(color));
	else
		return (color * (30000 / ITERATIONS));
}
