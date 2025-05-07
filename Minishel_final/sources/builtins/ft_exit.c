/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:07:29 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 11:07:31 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

int	ft_verif_nb(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_cmd *command, t_data *data)
{
	data->exit = 0;
	if ((data->nb_pipes == 0 && !command->arg[1])
		|| (data->nb_pipes == 0 && command->arg[1]
			&& ft_verif_nb(command->arg[1])))
		data->exit = 1;
	else
		data->return_value = 2;
	if (command->arg[1] && ft_verif_nb(command->arg[1]))
		data->return_value = ft_atoi(command->arg[1]);
	if (command->arg[1] && !(ft_verif_nb(command->arg[1])))
	{
		ft_putstr_fd("Ca c'est pas un nombre ", command->fd_out);
		ft_putstr_fd("wesh, réessaye\n", command->fd_out);
	}
}
