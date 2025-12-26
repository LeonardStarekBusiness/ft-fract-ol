/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:15:46 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/21 19:56:44 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# define FT_NAN (0.0f / 0.0f)
# define KEY_C 99
# define ARROW_LEFT   65361
# define ARROW_UP     65362
# define ARROW_RIGHT  65363
# define ARROW_DOWN   65364
# ifndef ITERATIONS
#  define ITERATIONS 15
# endif
# ifndef WIN_SIZE
#  define WIN_SIZE 800
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
	void		*mlx;
	void		*window;
	void		*img;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;

	char		*type;
	t_complex	z;
	int			exp;
	int			scheme;
	t_complex	topleft;
	double		size;
	int			depth;
}	t_window;

t_complex	sq_imag(t_complex num);
t_complex	pow_imag(t_complex num, int exp);
t_complex	add_imag(t_complex num1, t_complex num2);
double		ft_pow(double x, double y);
int			ft_isnan(double fp);
double			depth_level(double size);

int			iterations_mandel(t_complex c, int depth);
int			iterations_multi(t_complex c, int exp, int depth);
int			iterations_julia(t_complex c, t_complex z, int depth);
int			iterations_burning_ship(t_complex c, int depth);

void		make_window(t_window *win);
void		initialise(char *type, t_complex z, int exp);
int			draw_fractal(t_window *win);
void		draw_mandel(t_window *win, t_coord pixel);
void		draw_multi(t_window *win, t_coord pixel);
void		draw_julia(t_window *win, t_coord pixel);
void		draw_burning_ship(t_window *win, t_coord pixel);
t_complex	transform(t_coord pixel, t_window *win);

int			colorscheme(int color, int scheme);

void		throw_message(void);
double		ft_strtof(char *str);
#endif
