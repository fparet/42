/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:26:35 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:38:04 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_map(char *line)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	copy = line;
	len = ft_strlen(copy) - 1;
	if (len == 0)
		return (0);
	while (copy[i] == ' ')
		i++;
	if (len == i)
		return (0);
	while (i < len)
	{
		if (copy[i] != '0' && copy[i] != '1' && copy[i] != 'N'
			&& copy[i] != 'S' && copy[i] != 'E'
			&& copy[i] != 'W' && copy[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	nbr_line_map(char *file)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nopen file\n", 1), -1);
	line = get_next_line(fd);
	while (line && !is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), count);
}

int	map_malloc2(int fd, char *line, t_game *g)
{
	int	i;
	int	len;

	i = 0;
	while (line)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (g->map_width < len)
			g->map_width = len;
		g->map[i] = ft_strndup(line, len);
		if (!g->map[i++])
			return (free(line), ft_putstr_fd("Error\nmalloc\n", 1), -1);
		free(line);
		line = get_next_line(fd);
	}
	g->map[i] = NULL;
	return (0);
}

int	map_malloc(char *file, t_game *g)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nopen file\n", 1), -1);
	line = get_next_line(fd);
	while (line && !is_map(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (map_malloc2(fd, line, g) == -1)
		return (close(fd), -1);
	return (close(fd), 0);
}

int	map(char *file, t_game *g)
{
	g->map_height = nbr_line_map(file);
	if (g->map_height < 3)
		return (ft_putstr_fd("Error\ninvalid map min 3 height\n", 1), -1);
	g->map = (char **)malloc((g->map_height + 1) * sizeof(char *));
	if (!g->map)
		return (ft_putstr_fd("Error\nmalloc\n", 1), -1);
	if (map_malloc(file, g) == -1)
		return (-1);
	return (0);
}
