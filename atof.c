/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:03:19 by fparet            #+#    #+#             */
/*   Updated: 2025/01/07 04:03:21 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!((c >= '0') && (c <= '9')))
		return (0);
	return (1);
}

// Ignore les espaces initiaux et retourne le pointeur avancé
const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

// Gère le signe et retourne 1 pour positif ou -1 pour négatif
int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

// Convertit la partie entière ou décimale selon les paramètres donnés
double	convert_number(const char **str, double factor)
{
	double	result;

	result = 0.0;
	while (**str && ft_isdigit(**str))
	{
		if (factor < 1.0)
		{
			result += (**str - '0') * factor;
			factor *= 0.1;
		}
		else
		{
			result = result * 10.0 + (**str - '0');
		}
		(*str)++;
	}
	return (result);
}

// Fonction principale : convertit une chaîne en double
double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	str = skip_spaces(str);
	sign = parse_sign(&str);
	result = convert_number(&str, 1.0);
	if (*str == '.')
	{
		str++;
		result += convert_number(&str, 0.1);
	}
	return (result * sign);
}
