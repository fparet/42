/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:27:11 by fparet            #+#    #+#             */
/*   Updated: 2025/01/07 04:27:13 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Génère une couleur RGB en fonction de 
//	l'itération actuelle, avec une 
//		pondération différente pour chaque canal
// Génère une couleur bleue qui varie linéairement avec l'itération
int	get_color(int iteration, int max_iter, int color_set)
{
	if (iteration == max_iter)
		return (0x000000);
	if (color_set == 0)
		return (((iteration * 13) % 256 << 16)
			| ((iteration * 7) % 256 << 8)
			| ((iteration * 3) % 256));
	else
		return ((iteration * 0x0000FF / max_iter) & 0xFFFFFF);
}

// Écrit la couleur calculée dans la mémoire du pixel correspondant
void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// Vérifie si le module reste inférieur ou égal à 2
// Temporaire pour zr
// zi = 2*zr*zi + im
// zr mis à jour
// Retourne le nombre d'itérations avant divergence ou convergence
int	calculate_mandelbrot(double coords[4], t_fractol *f)
{
	double	tmp;
	int		i;

	i = -1;
	while (++i < f->max_iter
		&& (coords[2] * coords[2] + coords[3] * coords[3] <= 4))
	{
		tmp = coords[2] * coords[2] - coords[3] * coords[3] + coords[0];
		coords[3] = 2 * coords[2] * coords[3] + coords[1];
		coords[2] = tmp;
	}
	return (i);
}

// Parcourt chaque ligne
// Parcourt chaque colonne
// Calcul de re
// Calcul de im
// Initialisation de zr
// Initialisation de zi
// Calcule les itérations pour le point
// Place le pixel avec la couleur correspondante
void	draw_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	double	coords[4];
	int		i;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			coords[0] = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
			coords[1] = f->max_im - y * (f->max_im - f->min_im) / HEIGHT;
			coords[2] = coords[0];
			coords[3] = coords[1];
			i = calculate_mandelbrot(coords, f);
			put_pixel(&f->img, x, y, get_color(i, f->max_iter, f->color_set));
		}
	}
}

// Parcourt chaque ligne
// Parcourt chaque colonne
// Initialisation de zr
// Initialisation de zi
// Calcul de zr
// Calcul de zi
// Vérifie la divergence
// Place le pixel avec la couleur correspondante
// coords[0] = zr, coords[1] = zi, coords[2] = tmp_re
// zr = coord [0]
//zi = coord [1]
//tmp = coord
void	draw_julia(t_fractol *f)
{
	int		x;
	int		y;
	int		i;
	double	c[3];

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c[0] = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
			c[1] = f->max_im - y * (f->max_im - f->min_im) / HEIGHT;
			i = -1;
			while (++i < f->max_iter)
			{
				c[2] = c[0];
				c[0] = c[0] * c[0] - c[1] * c[1] + f->c_re;
				c[1] = 2 * c[2] * c[1] + f->c_im;
				if (c[0] * c[0] + c[1] * c[1] > 4)
					break ;
			}
			put_pixel(&f->img, x, y, get_color(i, f->max_iter, f->color_set));
		}
	}
}
