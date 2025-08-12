/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:31:54 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:10:09 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	g;

	init_game(&g);
	if (argc != 2)
		return (ft_putstr_fd("invalid argument number\n", 1), 0);
	if (file_is_valide(argv[1]) == -1)
		return (0);
	if (parsing(argv[1], &g) == -1)
		return (free_game(&g), 0);
	print_game(&g);
	setup_and_run(&g);
	free_game(&g);
}
