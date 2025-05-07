/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:45:15 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:24:24 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_etc.h"
#include "var_env.h"

void	increment_both(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

char	*fill_pid_str(char *buffer, int fd)
{
	char	*pid_str;
	size_t	i;

	pid_str = ft_calloc(32, sizeof(char));
	if (!pid_str)
	{
		perror("malloc");
		close(fd);
		return (NULL);
	}
	i = 0;
	while (buffer[i] != ' ' && buffer[i] != '\0' && i < 31)
	{
		pid_str[i] = buffer[i];
		i++;
	}
	pid_str[i] = '\0';
	close(fd);
	return (pid_str);
}

char	*get_pid(void)
{
	char	buffer[128];
	int		fd;
	int		n;
	char	*pid_str;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Can't get pid\n", 14);
		return (NULL);
	}
	n = read(fd, buffer, sizeof(buffer) - 1);
	if (n < 0)
	{
		perror("read");
		close(fd);
		return (NULL);
	}
	buffer[n] = '\0';
	pid_str = fill_pid_str(buffer, fd);
	return (pid_str);
}
