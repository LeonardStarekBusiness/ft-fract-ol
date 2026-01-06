/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarek <lstarek@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:15:46 by lstarek           #+#    #+#             */
/*   Updated: 2025/12/29 15:15:14 by lstarek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <mlx.h>
# include <sys/time.h>
# include "libft/libft.h"
# define FT_NAN (0.0f / 0.0f)
# define KEY_C 99
# define ARROW_LEFT   65361
# define ARROW_UP     65362
# define ARROW_RIGHT  65363
# define ARROW_DOWN   65364
# ifndef ITERATIONS
#  define ITERATIONS 24
# endif
# ifndef REDRAW_MS
#  define REDRAW_MS 300
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

	size_t		last_render;
	size_t		current_render;
	int			needs_redraw;
}	t_window;

t_complex	sq_imag(t_complex num);
t_complex	pow_imag(t_complex num, int exp);
t_complex	add_imag(t_complex num1, t_complex num2);
t_complex	c_abs(t_complex complex);
t_complex	transform(t_coord pixel, t_window *win);
double		ft_pow(double x, double y);
int			ft_isnan(double fp);
double		depth_level(double size);

int			iterations_mandel(t_complex c, int exp, int depth);
int			iterations_julia(t_complex c, t_complex z, int exp, int depth);
int			iterations_lennert(t_complex c, t_complex z, int exp, int depth);
int			iterations_burning_ship(t_complex c, int exp, int depth);

void		make_window(t_window *win);
void		init(char *type, t_complex z, int exp, char **av);
int			draw_fractal(t_window *win);
void		ft_put_pixel(t_window *win, t_coord pixel, int iter);

void		draw_mandel(t_window *win, t_coord pixel);
void		draw_julia(t_window *win, t_coord pixel);
void		draw_lennert(t_window *win, t_coord pixel);
void		draw_burning_ship(t_window *win, t_coord pixel);

int			colorscheme(int color, int scheme);

void		throw_message(void);
void		print_formula(char *type, int exp, char **av);
double		ft_strtof(char *str);

size_t		now_ms(void);
int			redraw(t_window *win);

#endif
