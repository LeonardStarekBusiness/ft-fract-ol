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

	square.real = (num.real * num.real) - (num.i * num.i);
	square.i = (num.real * num.i * 2.0);
	return (square);
}

t_complex	mul_imag(t_complex num1, t_complex num2)
{
	t_complex	multiple;

	multiple.real = num1.real * num2.real - num1.i * num2.i;
	multiple.i = num1.real * num2.i + num1.i * num2.real;
	return (multiple);
}

t_complex	pow_imag(t_complex num, int exp)
{
	t_complex	orig;

	orig = num;
	while (exp > 1)
	{
		num = mul_imag(num, orig);
		exp--;
	}
	return (num);
}

t_complex	add_imag(t_complex num1, t_complex num2)
{
	t_complex	sum;

	sum.real = num1.real + num2.real;
	sum.i = num1.i + num2.i;
	return (sum);
}
