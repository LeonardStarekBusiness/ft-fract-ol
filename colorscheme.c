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

int	color_ft(int c, int bitshift)
{
	if (c == -1)
		return (0x00000000);
	if (c == 0)
		return (10 << bitshift);
	else
		return (c * 10 << bitshift);
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
	b = 200 - (22 * c / 25);
	return ((r << 16) | (g << 8) | b);
}

int	colorscheme(int color, int scheme)
{
	if (scheme == 1)
		return (color_ft(color, 8));
	else if (scheme == 2)
		return (color_ft(color, 0));
	else if (scheme == 3)
	{
		if (color == -1)
			return (0x00dd007f);
		else
			return (color_purple(color));
	}
	else if (scheme == 4)
	{
		if (color == -1)
			return (0x002e293a);
		else
			return (color_lava(color));
	}
	else
		return (color_ft(color, 16));
}
