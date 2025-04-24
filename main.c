/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:13:20 by fparet            #+#    #+#             */
/*   Updated: 2025/01/07 04:13:23 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

bool	is_valid_number(const char *str)
{
	if (!str || *str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (false);
	while (*str && ((*str >= '0' && *str <= '9') || *str == '.'))
	{
		if (*str == '.')
		{
			str++;
			if (!(*str >= '0' && *str <= '9'))
				return (false);
		}
		else
			str++;
	}
	return (*str == '\0');
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	draw_fractal(t_fractol *f)
{
	if (f->fractal_type == 0)
		draw_mandelbrot(f);
	else if (f->fractal_type == 1)
		draw_julia(f);
}

void	set_julia_params(t_fractol *f, int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putstr("Error: Julia requires ");
		ft_putstr("exactly 2 parameters (c_re, c_im).\n");
		exit(1);
	}
	if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
	{
		write(1, "Error: Julia parameters must be valid numbers.\n", 47);
		exit(1);
	}
	if (argc == 4)
	{
		f->c_re = ft_atof(argv[2]);
		f->c_im = ft_atof(argv[3]);
		printf("Converted re: %f, im: %f\n", f->c_re, f->c_im);
		if ((f->c_re < -2.0 || f->c_re > 2.0)
			|| (f->c_im < -2.0 || f->c_im > 2.0))
		{
			ft_putstr("Error: Julia parameters ");
			ft_putstr("must be between -2.0 and 2.0\n");
			exit(1);
		}
	}
}

// Initialise la structure principale `f`, 
//		crée les fenêtres, images, et autres ressources nécessaires.
// Dessine la fractale choisie (Mandelbrot ou Julia).
// Affiche l'image générée dans la fenêtre créée par `mlx`.
// Attache un hook pour détecter 
//		les événements de la souris (ex : zoom avant/arrière).
// Attache un hook pour détecter les pressions de touches du clavier.
// Attache un hook pour gérer la 
//		fermeture de la fenêtre (ex : clic sur la croix).
// Boucle principale de la bibliothèque MiniLibX. 
//		Gère les événements graphiques et attend des interactions.
int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0
			&& ft_strcmp(argv[1], "julia") != 0))
	{
		display_usage();
		return (1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		f.fractal_type = 0;
	else
		f.fractal_type = 1;
	if (f.fractal_type == 1)
		set_julia_params(&f, argc, argv);
	init_fractol(&f);
	draw_fractal(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.ptr, 0, 0);
	mlx_mouse_hook(f.win, zoom, &f);
	mlx_key_hook(f.win, key_press, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}
