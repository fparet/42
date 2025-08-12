/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:55:55 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:35:59 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	character_is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j]
				!= 'W' && map[i][j] != ' ')
			{
				ft_putstr_fd("Error\ncharacter '", 2);
				ft_putchar_fd(map[i][j], 2);
				ft_putstr_fd("' is invalid\n", 2);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	player_is_valid(char **map)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player > 1)
		return (ft_putstr_fd("Error\nmultiple player\n", 2), -1);
	if (player < 1)
		return (ft_putstr_fd("Error\nmissing player\n", 2), -1);
	return (0);
}

int	is_invalid(char **map, int y, int x)
{
	if (y <= 0 || x <= 0 || !map[y + 1] || x >= (int)ft_strlen(map[y - 1])
		|| x >= (int)ft_strlen(map[y + 1]) || map[y][x + 1] == '\0')
		return (1);
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' ||
		map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	map_is_closed(char **map)
{
	char	c;
	int		y;
	int		x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (is_invalid(map, y, x))
				{
					ft_putstr_fd("Error\nMap not closed position: ", 2);
					ft_putnbr_fd(y, 2);
					ft_putstr_fd(",", 2);
					return (ft_putnbr_fd(x, 2), ft_putchar_fd('\n', 2), -1);
				}
			}
			x++;
		}
	}
	return (0);
}

int	map_is_valid(t_game g)
{
	if (character_is_valid(g.map) == -1)
		return (-1);
	if (player_is_valid(g.map) == -1)
		return (-1);
	if (map_is_closed(g.map) == -1)
		return (-1);
	return (0);
}
