/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:20:52 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:30:36 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/free_etc.h"
#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	ft_free(s1);
	return (s3);
}

char	*ft_strjoinenv(const char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	s3 = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	s3[i++] = '=';
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	return (s3);
}

// int	main(int a, char **v)
// {
// 	char *s;
// 	char *s2;

// 	s2[0] = '\0';
// 	if (a > 1)
// 	{
// 		s = ft_strjoin(s2, s2);
// 		printf("%s\n", s);
// 		free(s);
// 	}
// 	return (0);
// }