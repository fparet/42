/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_builtins2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:42:48 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 11:42:52 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

bool	verif_option(char *str)
{
	if (!str)
		return (false);
	if (str[0] == '-')
		return (true);
	return (false);
}

bool	verif_export(char *str)
{
	int		i;
	bool	signe_egual;

	i = 0;
	signe_egual = false;
	if (str[0] >= '0' && str[0] <= '9')
		return (false);
	while (str[i])
	{
		if (str[i] == '=')
		{
			signe_egual = true;
			break ;
		}
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] == '_') || (str[i] == '='))
			|| (str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (signe_egual);
}

int	ft_strcmpsize(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == ft_strlen(s1) && i == ft_strlen(s2))
		return (0);
	return (1);
}

bool	echo_verif(t_cmd *command, t_data *data)
{
	ft_echo(command->arg, command->fd_out);
	data->return_value = 0;
	return (true);
}

bool	exit_verif(t_cmd *command, t_data *data)
{
	if (!command || !command->arg || !command->arg[0])
		return (false);
	data->return_value = 2;
	if (command->arg[1] && !(ft_verif_nb(command->arg[1]))
		&& verif_option(command->arg[1]))
		ft_putstr_fd("option non prise en compte\n", 2);
	else if (command->arg[1] && command->arg[2])
		ft_putstr_fd("Trop d'arguments pelo\n", 2);
	else if (command->arg[1] && ft_verif_nb(command->arg[1])
		&& (!((command->arg[1][0] == '-' && ft_strlen(command->arg[1]) < 21)
			|| ft_strlen(command->arg[1]) < 20)))
		ft_putstr_fd("numeric argument required\n", 2);
	else if (command->arg[1] && ft_verif_nb(command->arg[1])
		&& !(command->arg[1][0] == '-') && ft_atoll(command->arg[1]) < 0)
		ft_putstr_fd("numeric argument required\n", 2);
	else if (command->arg[1] && ft_verif_nb(command->arg[1])
		&& command->arg[1][0] == '-'
		&& ft_atoll(command->arg[1]) > 0)
		ft_putstr_fd("numeric argument required\n", 2);
	else
		ft_exit(command, data);
	return (true);
}
