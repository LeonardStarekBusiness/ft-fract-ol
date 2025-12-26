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
	ft_putstr_fd("+-------------------------------------------", 1);
	ft_putstr_fd("----------------+\n\t\t***PROPER USE***\n\n./fractol", 1);
	ft_putstr_fd("\tmandelbrot\n\t\tship\n\t\tjulia", 1);
	ft_putstr_fd("\t\ta\t\tbi\n\t\tmulti\t\tn\n+--------------------------", 1);
	ft_putstr_fd("---------------------------------+\n", 1);
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
