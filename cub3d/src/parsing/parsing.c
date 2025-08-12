/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:46:02 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:46:15 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_game(t_game *g)
{
	int	i;

	i = 0;
	if (!g)
		return ;
	g->map = NULL;
	g->map_width = -1;
	g->map_height = -1;
	g->player_x = -1.0;
	g->player_y = -1.0;
	g->player_angle = -1.0;
	while (i < 4)
		g->texture[i++] = NULL;
	g->floor_color = -1;
	g->ceiling_color = -1;
}

int	file_is_valide(char *file)
{
	char	tmp[5];
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(file);
	if (len < 5)
		return (-1);
	len -= 4;
	while (file[len])
		tmp[i++] = file[len++];
	tmp[i] = '\0';
	if (ft_strcmp(tmp, ".cub"))
		return (ft_putstr_fd("invalid file .cub\n", 1), -1);
	i = open(file, O_RDONLY);
	if (i < 0)
		return (ft_putstr_fd("Error open file\n", 1), -1);
	close(i);
	return (0);
}

int	parse_process(char *copy, t_game *g)
{
	while (*copy == ' ')
		copy++;
	if (*copy != '\0' && *copy != '\n')
	{
		if (ft_strncmp(copy, "NO", 2) == 0 && texture(0, copy, g) == -1)
			return (-1);
		else if (ft_strncmp(copy, "SO", 2) == 0 && texture(1, copy, g) == -1)
			return (-1);
		else if (ft_strncmp(copy, "WE", 2) == 0 && texture(2, copy, g) == -1)
			return (-1);
		else if (ft_strncmp(copy, "EA", 2) == 0 && texture(3, copy, g) == -1)
			return (-1);
		else if (ft_strncmp(copy, "F", 1) == 0 && color_floor(copy, g) == -1)
			return (-1);
		else if (ft_strncmp(copy, "C", 1) == 0 && color_ceiling(copy, g) == -1)
			return (-1);
	}
	return (0);
}

int	parsing(char *file, t_game *g)
{
	char	*line;
	char	*copy;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nopen file\n", 1), -1);
	line = get_next_line(fd);
	while (line)
	{
		copy = line;
		if (parse_process(copy, g) == -1)
			return (free(line), close(fd), -1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!g->texture[0] || !g->texture[1] || !g->texture[2] || !g->texture[3])
		return (close(fd), ft_putstr_fd("Error\nmissing texture\n", 1), -1);
	if (map(file, g) == -1)
		return (-1);
	if (map_is_valid(*g) == -1)
		return (-1);
	player(g);
	return (0);
}
