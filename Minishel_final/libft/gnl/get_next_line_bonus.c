/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:36:51 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 04:54:07 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "get_next_line_bonus.h"

void	set_fail(bool *fail)
{
	*fail = false;
}

char	*ft_join_and_strchr(char *temp, char *buff, int c, int event)
{
	char	*temp2;
	size_t	i;

	i = 0;
	if (event == 1)
	{
		(void)c;
		temp2 = ft_strjoingnl(temp, buff);
		free(temp);
		return (temp2);
	}
	else if (event == 2)
	{
		(void)buff;
		while (temp[i] != '\0')
		{
			if (temp[i] == (unsigned char)c)
				return ((char *)&temp[i + 1]);
			i++;
		}
		if (temp[i] == (unsigned char)c)
			return ((char *)&temp[i + 1]);
		return (NULL);
	}
	return (NULL);
}

char	*get_line_2(char *temp)
{
	int		i;
	char	*str;
	char	*temp2;

	i = 0;
	temp2 = ft_join_and_strchr(temp, NULL, '\n', 2);
	if (!temp2)
		return (temp);
	else
	{
		str = ft_calloc((ft_strlen(temp) - ft_strlen(temp2)), sizeof(char));
		while (temp[i] != '\0' && temp[i] != '\n')
		{
			str[i] = temp[i];
			i++;
		}
		return (str);
	}
}

char	*get_line1(int fd, char *temp, int byte, bool *fail)
{
	char	*buff;

	if (!temp)
		temp = ft_calloc(1, sizeof(char));
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff || !temp)
		return (NULL);
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte <= 0)
		{
			set_fail(fail);
			break ;
		}
		buff[byte] = '\0';
		temp = ft_join_and_strchr(temp, buff, 0, 1);
		if (ft_join_and_strchr(temp, NULL, '\n', 2))
			break ;
	}
	free(buff);
	if (byte <= 0 && temp[0] == '\0')
		return (free(temp), NULL);
	return (temp);
}

char	*get_next_line(int fd, bool *fail)
{
	static char	*temp[1024];
	char		*str;
	int			byte;
	char		*temp2;

	byte = 1;
	if (fd == -10)
		return (clear_static(temp), NULL);
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (free(temp[fd]), temp[fd] = NULL, set_fail(fail), NULL);
	temp[fd] = get_line1(fd, temp[fd], byte, fail);
	if (!temp[fd])
		return (free(temp[fd]), NULL);
	str = get_line_2(temp[fd]);
	if (!str)
		return (NULL);
	if (!(ft_join_and_strchr(temp[fd], NULL, '\n', 2)))
		temp[fd] = NULL;
	else
	{
		temp2 = ft_strdup(ft_join_and_strchr(temp[fd], NULL, '\n', 2));
		free(temp[fd]);
		temp[fd] = temp2;
	}
	return (set_fail(fail), str);
}

// int	main(int ac, char **av)
// {
// 	char *line;
// 	int fd1;
// 	int i;
// 	bool fail;

// 	fail = true;

// 	(void)ac;
// 	line = get_next_line(0, &fail);
// 	while (line)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(0, &fail);
// 	}
// 	return (0);
// }