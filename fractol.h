/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:58:30 by fparet            #+#    #+#             */
/*   Updated: 2025/01/07 04:58:32 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	c_re;
	double	c_im;
	int		max_iter;
	int		fractal_type;
	int		color_set;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_fractol;

const char	*skip_spaces(const char *str);
t_complex	calculate_zoom_center(int x, int y, t_fractol *f);
void		init_fractol(t_fractol *f);
void		draw_mandelbrot(t_fractol *f);
void		put_pixel(t_img *img, int x, int y, int color);
int			close_window(t_fractol *f);
int			zoom(int button, int x, int y, t_fractol *f);
int			key_press(int keycode, t_fractol *f);
void		draw_fractal(t_fractol *f);
void		set_init_mandel(t_fractol *f);
int			calculate_mandelbrot(double coords[4], t_fractol *f);
int			ft_isdigit(int c);
int			parse_sign(const char **str);
double		convert_number(const char **str, double factor);
double		ft_atof(const char *str);
int			ft_strcmp(char *s1, char *s2);
void		draw_julia(t_fractol *f);
void		display_usage(void);
void		ft_putstr(const char *str);

#endif
