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

int	iterations_mandel(t_complex c, int exp, int depth)
{
	int			i;
	t_complex	z;

	if (ft_isnan(c.real) || ft_isnan(c.i))
		return (-1);
	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	while (i < depth)
	{
		if (((z.real * z.real) + (z.i * z.i)) > 4.0)
			return (i);
		if (exp == 2)
			z = add_imag(sq_imag(z), c);
		else
			z = add_imag(pow_imag(z, exp), c);
		i++;
	}
	return (-1);
}

int	iterations_burning_ship(t_complex c, int exp, int depth)
{
	int			i;
	t_complex	z;

	if (ft_isnan(c.real) || ft_isnan(c.i))
		return (-1);
	i = 0;
	z.real = 0.0;
	z.i = 0.0;
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

int	iterations_julia(t_complex c, t_complex z, int exp, int depth)
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
			z = add_imag(sq_imag(z), c);
		else
			z = add_imag(pow_imag(z, exp), c);
		i++;
	}
	return (-1);
}
