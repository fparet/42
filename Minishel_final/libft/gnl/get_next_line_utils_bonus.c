/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:36:46 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 04:12:31 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "get_next_line_bonus.h"

void	destroy(void)
{
	get_next_line(-10, NULL);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *)malloc(len1 + len2 + 1);
	i = 0;
	j = 0;
	if (!s3)
		return (NULL);
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < len2)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

void	clear_static(char **tmp)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (tmp[i])
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
		i++;
	}
}
