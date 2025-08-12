/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:02:49 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/09 20:04:45 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i] && i < n)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (0);
	i = 0;
	while (s[i] && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
