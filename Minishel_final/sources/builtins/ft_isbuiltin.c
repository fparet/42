/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:08:24 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 11:08:30 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

bool	ft_handle_is_builtin(char *cmd)
{
	if (ft_strncmp("cd", cmd, 3) == 0)
		return (true);
	else if (ft_strncmp("export", cmd, 7) == 0)
		return (true);
	else if (ft_strncmp("unset", cmd, 6) == 0)
		return (true);
	return (false);
}

bool	ft_verif_is_bultins(t_cmd *command)
{
	if (ft_strncmp("echo", command->arg[0], 5) == 0)
		return (true);
	if (ft_strncmp("exit", command->arg[0], 5) == 0)
		return (true);
	else if (ft_strncmp("env", command->arg[0], 4) == 0)
		return (true);
	else if (ft_strncmp("pwd", command->arg[0], 4) == 0)
		return (true);
	if (ft_handle_is_builtin(command->arg[0]))
		return (true);
	return (false);
}
