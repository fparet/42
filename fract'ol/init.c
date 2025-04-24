/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:53:23 by fparet            #+#    #+#             */
/*   Updated: 2025/01/07 03:53:30 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

void	set_init_mandel(t_fractol *f)
{
	f->min_re = -2.0;
	f->max_re = 1.0;
	f->min_im = -1.5;
	f->max_im = 1.5;
}

// Initialise la connexion avec la bibliothèque MiniLibX.
// Vérifie si l'initialisation a échoué.
// Quitte le programme en cas d'erreur.
// Crée une nouvelle fenêtre avec les dimensions spécifiées.
// Vérifie si la création de la fenêtre a échoué.
// Quitte le programme en cas d'erreur.
// Crée une nouvelle image pour dessiner les fractales.
// Vérifie si la création de l'image a échoué.
// Quitte le programme en cas d'erreur.
// Obtient l'adresse mémoire de l'image pour y écrire des pixels.
// Définit le nombre maximum d'itérations pour les calculs de fractales.
// Initialise le jeu de couleurs utilisé pour dessiner les fractales.
// Vérifie quel type de fractale est 
//		demandé et initialise les paramètres correspondants.
// Appelle une fonction spécifique pour initialiser les bornes de Mandelbrot.
// Mandelbrot = 0
//Julia = 1
void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!f->win)
		exit(1);
	f->img.ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.ptr)
		exit(1);
	f->img.addr = mlx_get_data_addr(f->img.ptr, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	f->max_iter = 50;
	f->color_set = 0;
	if (f->fractal_type == 0)
	{
		set_init_mandel(f);
	}
	else if (f->fractal_type == 1)
	{
		f->min_re = -2.0;
		f->max_re = 2.0;
		f->min_im = -2.0;
	f->max_im = 2.0;
	}
}

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	display_usage(void)
{
	ft_putstr("Usage: ./fractol [mandelbrot");
	ft_putstr(" | julia] [c_re c_im (optional for julia)]\n");
	ft_putstr("  mandelbrot        : Affiche la fractale de Mandelbrot.\n");
	ft_putstr("  julia [c_re c_im] : Affiche l");
	ft_putstr("a fractale de Julia avec les paramètres c_re et c_im.\n");
	ft_putstr("    c_re, c_im      : Les paramètres ");
	ft_putstr("doivent être compris entre -2.0 et 2.0.\n");
	exit(1);
}
