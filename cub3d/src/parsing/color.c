/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:47:00 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:37:45 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	color_conversion(char *tmp)
{
	int	i;
	int	j;
	int	cannals[3];

	i = 0;
	j = 0;
	while (j < 3)
	{
		cannals[j] = ft_atoi(&tmp[i]);
		if (cannals[j] > 255)
			return (ft_putstr_fd("Error\ncannals RGB range [0-255]\n", 1), -1);
		while (tmp[i] != ',' && tmp[i] != '\n')
			i++;
		if (tmp[i] == ',')
			i++;
		j++;
	}
	/* printf("%d %d %d\n", cannals[0], cannals[1], cannals[2]); */
	return ((cannals[0] << 16) | (cannals[1] << 8) | cannals[2]);
}

int	color_pattern(char *tmp)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while ((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == ',')
	{
		if (tmp[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2 || i != ((int)ft_strlen(tmp) - 1)
		|| tmp[0] == ',' || tmp[i - 1] == ',')
		return (printf("Error\ninvalid format [R,G,B]\n"), -1);
	return (color_conversion(tmp));
}

int	color_floor(char *line, t_game *g)
{
	char	*tmp;

	if (g->floor_color != -1)
		return (ft_putstr_fd("Error\nmultiple floor color\n", 1), -1);
	line++;
	while (*line && *line == ' ')
		line++;
	if (*line == '\0')
		return (ft_putstr_fd("Error\ninvalid floor color\n", 1), -1);
	tmp = ft_strdup(line);
	if (tmp == NULL)
		return (ft_putstr_fd("Error\nmalloc\n", 1), -1);
	g->floor_color = color_pattern(tmp);
	if (g->floor_color == -1)
		return (free(tmp), -1);
	return (free(tmp), 0);
}

int	color_ceiling(char *line, t_game *g)
{
	char	*tmp;

	if (g->ceiling_color != -1)
		return (ft_putstr_fd("Error\nmultiple ceiling color\n", 1), -1);
	line++;
	while (*line && *line == ' ')
		line++;
	if (*line == '\0')
		return (ft_putstr_fd("Error\ninvalid ceiling color\n", 1), -1);
	tmp = ft_strdup(line);
	if (tmp == NULL)
		return (ft_putstr_fd("Error\nmalloc\n", 1), -1);
	g->ceiling_color = color_pattern(tmp);
	if (g->ceiling_color == -1)
		return (free(tmp), -1);
	return (free(tmp), 0);
}
