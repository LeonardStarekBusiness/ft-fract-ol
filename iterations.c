/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:33:12 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/21 18:33:13 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterations_mandel(t_complex c)
{
	int			i;
	t_complex	z;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	while (i < ITERATIONS)
	{
		if (((z.real * z.real) + (z.i * z.i)) > 4)
			return (i);
		z = add_imag(sq_imag(z), c);
		i++;
	}
	return (-1);
}

t_complex	c_abs(t_complex complex)
{
	if (complex.real < 0.0)
		complex.real = -complex.real;
	if (complex.i < 0.0)
		complex.i = -complex.i;
	return (complex);
}

int	iterations_burning_ship(t_complex c)
{
	int			i;
	t_complex	z;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	while (i < ITERATIONS)
	{
		if (((z.real * z.real) + (z.i * z.i)) > 4)
			return (i);
		z = add_imag(sq_imag(c_abs(z)), c);
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
