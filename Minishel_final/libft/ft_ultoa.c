/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:04:48 by igrousso          #+#    #+#             */
/*   Updated: 2025/02/25 09:13:20 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ullen(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_ultoa(unsigned long nb)
{
	unsigned long long	n;
	int					sign;
	int					len;
	char				*str;

	n = nb;
	sign = 0;
	len = ullen(nb) + sign;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign == 1)
		str[0] = '-';
	while (len > sign)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int a, char **v)
// {
// 	char	*str;

// 	if (a >= 1)
// 	{
// 		str = ft_ultoa(atoll(v[1]));
// 		printf("%s\n", str);
// 		free(str);
// 	}
// 	return (0);
// }
