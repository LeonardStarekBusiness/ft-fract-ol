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
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# define NAN (0.0f / 0.0f)
# define KEY_C 99
# define ARROW_LEFT   65361
# define ARROW_UP     65362
# define ARROW_RIGHT  65363
# define ARROW_DOWN   65364
# ifndef ITERATIONS
#  define ITERATIONS 150
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
	int			scheme;
	t_complex	topleft;
	double		size;
}	t_window;

t_complex	sq_imag(t_complex num);
t_complex	add_imag(t_complex num1, t_complex num2);
double		ft_pow(double x, double y);
int			ft_isnan(double fp);

int			iterations_mandel(t_complex c);
int			iterations_julia(t_complex c, t_complex z);
int			iterations_burning_ship(t_complex c);

void		make_window(t_window *win);
void		draw_mandel(t_window *win);
void		draw_julia(t_window *win);
void		draw_burning_ship(t_window *win);
t_coord		transform(t_complex point, t_complex topleft, double size);

int			colorscheme(int color, int scheme);

void		throw_message(void);
double		ft_strtof(char *str);
#endif
