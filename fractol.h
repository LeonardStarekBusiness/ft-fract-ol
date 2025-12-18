/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:15:46 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/18 15:18:07 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>
# ifndef ITERATIONS
#  define ITERATIONS 100
# endif
# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif
# ifndef COLORSCHEME
#  define COLORSCHEME 2
# endif

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_window;

t_complex	sq_imag(t_complex num);
t_complex	add_imag(t_complex num1, t_complex num2);
void		print_i(t_complex num);

void		make_window(int julia, t_complex Z);
void		draw_mandel(t_window *win);
void		draw_julia(t_window *win, t_complex Z);
void		put_pixel(t_window *win, int x, int y, int color);
t_coord		transform(t_complex point, t_complex topleft, double size);

int			colorscheme(int color);
#endif
