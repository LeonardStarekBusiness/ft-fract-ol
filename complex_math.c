/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:16:01 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/18 15:19:56 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sq_imag(t_complex num)
{
	t_complex	square;
	double		r;
	double		i;

	r = num.real;
	i = num.i;
	square.real = (r * r) - (i * i);
	square.i = (r * i * 2);
	return (square);
}

t_complex	add_imag(t_complex num1, t_complex num2)
{
	t_complex	sum;

	sum.real = num1.real + num2.real;
	sum.i = num1.i + num2.i;
	return (sum);
}

t_coord	transform(t_complex point, t_complex topleft, double size)
{
	t_coord		fpoint;

	fpoint.x = (point.real - topleft.real) * (WIDTH / size);
	fpoint.y = (-point.i - topleft.i) * (HEIGHT / size);
	return (fpoint);
}
