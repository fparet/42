/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:02:06 by qboutel           #+#    #+#             */
/*   Updated: 2025/06/23 17:28:51 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_add_memory(char *memory, char *buffer)
{
	char	*addmem;

	addmem = ft_strjoin(memory, buffer);
	free(memory);
	return (addmem);
}

static char	*ft_clean_memory(char *memory)
{
	size_t	i;
	size_t	len;
	char	*clean;

	i = 0;
	if (memory == NULL)
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	len = ft_strlen(memory);
	clean = ft_substr(memory, i + 1, len);
	free(memory);
	return (clean);
}

static char	*ft_line(char *memory)
{
	size_t	i;
	size_t	j;
	int		n;
	char	*line;

	i = 0;
	j = 0;
	n = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		n = 1;
	line = (char *) malloc(i + n + 1);
	if (line == NULL)
		return (free(memory), NULL);
	while (j < i)
	{
		line[j] = memory[j];
		j++;
	}
	if (n == 1)
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *memory)
{
	ssize_t		ret;
	char		*buffer;

	ret = 1;
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (free(buffer), free(memory), NULL);
		buffer[ret] = '\0';
		memory = ft_add_memory(memory, buffer);
		if (memory == NULL)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (ret == 0 && ft_strlen(memory) == 0)
		return (free(memory), NULL);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	if (!memory)
	{
		memory = ft_strdup("");
		if (memory == NULL)
			return (NULL);
	}
	memory = ft_read(fd, memory);
	if (memory == NULL)
		return (NULL);
	line = ft_line(memory);
	memory = ft_clean_memory(memory);
	return (line);
}
/*
# include <stdio.h>
int	main(void)
{
	char	*line;
	int		fd;

	line = "ss";
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("main ==> %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/