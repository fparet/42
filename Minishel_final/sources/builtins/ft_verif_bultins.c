/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_bultins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:38:43 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 11:38:48 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

bool	verif_cd(t_cmd *command, t_data *data)
{
	data->return_value = 1;
	if (data->nb_pipes > 0)
		return (true);
	ft_cd(data->envp, command->arg[1], data);
	return (true);
}

void	while_verif_cmd(t_cmd *command, t_data *data)
{
	int	i;

	i = 0;
	while (command->arg[1 + i])
	{
		if (!(verif_export(command->arg[1 + i])))
		{
			ft_putstr_fd("Mauvaise syntaxe\n", 2);
			data->return_value = 2;
		}
		else
		{
			ft_export(&data->envp, command->arg[1 + i]);
			data->return_value = 0;
		}
		i++;
	}
}

bool	verif_cmd_export(t_cmd *command, t_data *data)
{
	data->return_value = 2;
	if (data->nb_pipes > 0)
		return (true);
	if (!(command->arg[1]))
	{
		print_exported_variables(data->envp);
		data->return_value = 0;
		return (true);
	}
	if (verif_option(command->arg[1]))
	{
		ft_putstr_fd("option non prise en compte\n", 2);
		data->return_value = 2;
		return (true);
	}
	if (command->arg[1])
	{
		while_verif_cmd(command, data);
		return (true);
	}
	return (true);
}

bool	verif_unset(t_cmd *command, t_data *data)
{
	int	i;

	i = 1;
	data->return_value = 2;
	if (data->nb_pipes > 0)
		return (true);
	if (!(command->arg[1]))
		return (true);
	if (verif_option(command->arg[1]))
	{
		ft_putstr_fd("option non prise en compte\n", 2);
		return (true);
	}
	else
	{
		while (command->arg[i])
		{
			ft_unset(&data->envp, command->arg[i]);
			i++;
		}
	}
	data->return_value = 0;
	return (true);
}

bool	ft_verif_bultins(t_cmd *command, t_data *data)
{
	bool	value;

	if (ft_strncmp("echo", command->arg[0], 5) == 0)
		value = echo_verif(command, data);
	else if (ft_strncmp("exit", command->arg[0], 5) == 0)
		value = exit_verif(command, data);
	else if (ft_strncmp("env", command->arg[0], 4) == 0)
		value = verif_env(command, data);
	else if (ft_strncmp("pwd", command->arg[0], 4) == 0)
		value = verif_pwd(command, data);
	else if (ft_strncmp("cd", command->arg[0], 3) == 0)
		value = verif_cd(command, data);
	else if (ft_strncmp("export", command->arg[0], 7) == 0)
		value = verif_cmd_export(command, data);
	else if (ft_strncmp("unset", command->arg[0], 6) == 0)
		value = verif_unset(command, data);
	else
		value = false;
	return (value);
}
