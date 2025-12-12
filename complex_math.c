#include "fractol.h"

//square of an imaginary number
t_complex sq_imag(t_complex num)
{
	t_complex square;
	double	r;
	double	i;

	r = num.real;
	i = num.i;
	square.real = (r*r)-(i*i);
	square.i = (r*i*2);

	return (square);
}

t_complex add_imag(t_complex num1, t_complex num2)
{
	t_complex	sum;

	sum.real = num1.real + num2.real;
	sum.i = num1.i + num2.i;

	return (sum);
}

void print_i(t_complex num)
{
	printf("(%.2f, %.2fi)\n", num.real, num.i);
}

