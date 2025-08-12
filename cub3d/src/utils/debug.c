/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:16:57 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:07:41 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* PASSE PAS A LA NORMINETTE */
/* DEBUG NON UTILISE DANS LE CODE FINAL */ 
void	print_game(t_game *g)
{
	int	i;

	if (!g)
		return ;
	printf("\n\n===== GAME STATE =====\n");
	printf("Map (W:%d x H:%d)\n", g->map_width, g->map_height);
	printf("--------------------------\n");
	for (i = 0; g->map[i]; i++)
		printf("%s\n", g->map[i]);
	printf("--------------------------\n");
	printf("Player Position : (x = %.2f, y = %.2f)\n", g->player_x, g->player_y);
	printf("Player Angle    : %.2f radians\n\n", g->player_angle);
	printf("Textures:\n");
	printf("  North: %s\n", g->texture[0] ? g->texture[0] : "(null)");
	printf("  South: %s\n", g->texture[1] ? g->texture[1] : "(null)");
	printf("  East : %s\n", g->texture[2] ? g->texture[2] : "(null)");
	printf("  West : %s\n", g->texture[3] ? g->texture[3] : "(null)");
	printf("Floor Color     : 0x%06X\n", g->floor_color);
	printf("Ceiling Color   : 0x%06X\n", g->ceiling_color);
	printf("==========================\n\n");
}

