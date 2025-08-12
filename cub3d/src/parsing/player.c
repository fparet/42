/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:18:58 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:36:50 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	position_player(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'N' || g->map[y][x] == 'S'
				|| g->map[y][x] == 'E' || g->map[y][x] == 'W')
			{
				g->player_x = x + 0.5;
				g->player_y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	orientation_player(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'N')
				g->player_angle = M_PI_2;
			else if (g->map[y][x] == 'S')
				g->player_angle = 3 * M_PI_2;
			else if (g->map[y][x] == 'E')
				g->player_angle = 0;
			else if (g->map[y][x] == 'W')
				g->player_angle = M_PI;
			x++;
		}
		y++;
	}
}

void	player(t_game *g)
{
	position_player(g);
	orientation_player(g);
}
