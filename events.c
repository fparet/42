/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:20:38 by fparet            #+#    #+#             */
/*   Updated: 2025/01/07 03:20:41 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Touche ESC pour quitter
int	key_press(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		close_window(f);
	return (0);
}

int	close_window(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.ptr);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
	return (0);
}

// Fonction qui calcule les coordonnées du 
	//centre de zoom en fonction de la position du curseur
// Calcul des coordonnées complexes correspondant à la position du curseur
t_complex	calculate_zoom_center(int x, int y, t_fractol *f)
{
	t_complex	center;

	center.re = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
	center.im = f->max_im - y * (f->max_im - f->min_im) / HEIGHT;
	return (center);
}

// Fonction de zoom qui est appelée à chaque clic de la molette de la souris
// Molette avant (4) ou arrière (5)
// Récupération des coordonnées du centre de zoom
// Détermination du facteur de zoom : 
//		plus petit que 1 pour un 
//		zoom avant, plus grand que 1 pour un zoom arrière
// Ajustement des bornes du plan complexe en fonction du facteur de zoom
// Déstruction de l'image précédente pour éviter les artefacts
// Création d'une nouvelle image vide après le zoom
// Redessine la fractale avec les nouvelles bornes
// Affiche l'image redessinée dans la fenêtre
int	zoom(int button, int x, int y, t_fractol *f)
{
	t_complex	center;
	double		zoom_factor;

	center = calculate_zoom_center(x, y, f);
	if (button == 4)
	zoom_factor = 0.9;
	else if (button == 5)
	zoom_factor = 1.1;
	else
		return (0);
	f->min_re = center.re + (f->min_re - center.re) * zoom_factor;
	f->max_re = center.re + (f->max_re - center.re) * zoom_factor;
	f->min_im = center.im + (f->min_im - center.im) * zoom_factor;
	f->max_im = center.im + (f->max_im - center.im) * zoom_factor;
	mlx_destroy_image(f->mlx, f->img.ptr);
	f->img.ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.ptr, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	draw_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr, 0, 0);
	return (0);
}
