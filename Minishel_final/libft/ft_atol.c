/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:00:13 by igrousso          #+#    #+#             */
/*   Updated: 2025/02/25 09:03:51 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *s)
{
	long	n;
	int		i;
	int		moins;

	i = 0;
	n = 0;
	moins = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == 43)
		i++;
	else if (s[i] == 45)
	{
		moins = -moins;
		i++;
	}
	while (ft_isdigit(s[i]) != 0 && s[i] != '\0')
		n = n * 10 + (s[i++] - 48);
	return (n * moins);
}
