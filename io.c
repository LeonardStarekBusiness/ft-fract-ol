/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:21:34 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/19 16:21:52 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	throw_message(void)
{
	ft_printf("+-------------------------------------------+\n");
	ft_printf("|            ***PROPER USE***               |\n");
	ft_printf("|                                           |\n");
	ft_printf("| ./fractol    mandelbrot              [n]  |\n");
	ft_printf("|              ship                    [n]  |\n");
	ft_printf("|              julia         a  bi     [n]  |\n");
	ft_printf("+-------------------------------------------+\n");
}

void	print_formula(char *type, int exp, char **av)
{
	ft_printf("\nFormula for the iterations:\n");
	if (!ft_strncmp(type, "julia", 6))
		ft_printf("Z(0) = parameter\nc = (%s, %si)", av[2], av[3]);
	else if (!ft_strncmp(type, "lennert", 8))
		ft_printf("Z(0) = parameter\nc = (%s, %si)", "-0.5", "-0.5");
	else
		ft_printf("Z(0) = (0, 0i)\nc = parameter", 1);
	ft_printf("\nZ(n+1) = ", 1);
	if (!ft_strncmp(type, "ship", 5) || !ft_strncmp(type, "lennert", 8))
		ft_printf("|", 1);
	ft_printf("Z");
	if (!ft_strncmp(type, "ship", 5) || !ft_strncmp(type, "lennert", 8))
		ft_printf("|", 1);
	ft_printf("^%d + c\n\n", exp);
}

double	ft_strtof_util(double fp, char after_comma, char c)
{
	if (after_comma > 0)
	{
		fp *= ft_pow(10, after_comma - 1);
		fp += c - 48;
		fp /= ft_pow(10, after_comma - 1);
	}
	else
	{
		fp *= 10.0;
		fp += c - 48;
	}
	return (fp);
}

double	ft_strtof(char *str)
{
	double	fp;
	char	after_comma;
	char	is_negative;

	after_comma = 0;
	fp = 0.0;
	is_negative = (*str == '-');
	str += is_negative;
	while (*str != 0)
	{
		if (ft_isdigit(*str))
		{
			fp = ft_strtof_util(fp, after_comma, *str);
			if (after_comma > 0)
				after_comma++;
		}
		else if (*str == '.' && after_comma == 0)
			after_comma = 1;
		else
			return (FT_NAN);
		str++;
	}
	if (is_negative)
		return (-fp);
	return (fp);
}
