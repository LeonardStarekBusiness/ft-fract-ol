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

int	color_lava(int color)
{
	return (255 << 16) | ((165 * (10 - color) / 9) << 8);
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

int	colorscheme(int color)
{
	switch (COLORSCHEME)
	{
		case (0):
			return (color * 1250);
		case (1):
			switch (color)
			{
				case (-1):
					return (0x002e293a);
				default:
					return (color_lava(color));
			}
		case (2):
			switch (color)
			{
				case (-1):
					return (0x00DDDDDD);
				default:
					return (color_ice(color));
			}
		case (3):
			switch (color)
			{
				case (-1):
					return (0x00F8E2D4);
				default:
					return (color_purple(color));
			}
	}
}


