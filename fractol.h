#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef ITERATIONS
# define ITERATIONS 700
#endif

typedef struct	s_complex
{
	double	real;
	double	i;
}	t_complex;

t_complex	sq_imag(t_complex num);
t_complex	add_imag(t_complex num1, t_complex num2);
void		print_i(t_complex num);