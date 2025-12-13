#include "fractol.h"

//returns amount of iterations until r or i part is > 2
//if reaches ITERATIONS: return -1 -->number is indeed in the set.
int	iterations_mandel(t_complex c)
{
	int		i;
	t_complex	z;

	i = 0;
	z.real = 0;
	z.i = 0;
	while (i < ITERATIONS)
	{
		if (((z.real * z.real) + (z.i * z.i)) > 4)
			return (i);
		// Z = Z² + c
		z = add_imag(sq_imag(z), c);
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
		// Z = Z² + c
		z = add_imag(sq_imag(z), c);
		i++;
	}
	return (-1);
}

int main(int ac, char **av)
{
	t_complex c;
	t_complex Z;

	c.real = -2.5;
	c.i = -2.0;

	if (ac == 2 && strncmp(av[1], "mandelbrot", 10) == 0)
	{
		while (c.i < 2.0)
		{
			c.real = -2.0;
			printf("\n");
			while (c.real < 2.5)
			{
				int x = iterations_mandel(c);
				if (x == -1)
					printf("@");
				else if (x > 2 && x < 10)
					printf("%d", x);
				else
					printf(" ");
				c.real += 0.02;
			}
		c.i += 0.02;
		}
	}
	else if (ac == 4 && strncmp(av[1], "julia", 5) == 0)
	{
		Z.real = strtof(av[2], NULL);
		Z.i = strtof(av[3], NULL);
		while (c.i < 2.0)
		{
			c.real = -2.0;
			printf("\n");
			while (c.real < 2.5)
			{
				int x = iterations_julia(Z, c);
				if (x == -1)
					printf("@");
				else if (x > 2 && x < 10)
					printf("%d", x);
				else
					printf(" ");
				c.real += 0.02;
			}
		c.i += 0.02;
		}
	}
	else
		printf("Proper usage: ./out  mandelbrot/julia  0.0  0.0");
}

