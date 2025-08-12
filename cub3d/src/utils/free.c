/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:16:01 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:06:51 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*free_game(t_game *g)
{
	free_split(g->map);
	free_textures(g->texture);
	return (NULL);
}

char	*free_split(char **split)
{
	int	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i] != NULL)
	{
		if (split[i])
		{
			free(split[i]);
			split[i] = NULL;
		}
		i++;
	}
	free(split);
	split = NULL;
	return (NULL);
}

char	*free_textures(char *texture[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (texture[i])
		{
			free(texture[i]);
			texture[i] = NULL;
		}
		i++;
	}
	return (NULL);
}
