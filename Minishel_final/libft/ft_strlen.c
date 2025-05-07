/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:34:58 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:19:52 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/free_etc.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlenvar(char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s && s[i] != '\0')
		i++;
	if (c == '?' || c == '$')
		ft_free(s);
	return (i);
}
