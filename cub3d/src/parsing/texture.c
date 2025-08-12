/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:40:26 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:28:39 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	texture(int index, char *line, t_game *g)
{
	if (g->texture[index])
		return (ft_putstr_fd("Error\nmultiple texture\n", 1), -1);
	line += 2;
	while (*line && *line == ' ')
		line++;
	if (*line == '\0')
		return (ft_putstr_fd("Error\ninvalid texture\n", 1), -1);
	g->texture[index] = ft_strdup(line);
	if (g->texture[index] == NULL)
		return (ft_putstr_fd("Error\nmalloc\n", 1), -1);
	return (0);
}
