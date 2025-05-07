/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:11:08 by igrousso          #+#    #+#             */
/*   Updated: 2025/02/25 09:11:35 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *s)
{
	long long	n;
	int			i;
	int			moins;

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
