/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_builtins3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:42:18 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 11:42:21 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

t_env	*cd_tiret(t_env *env_list)
{
	t_env	*oldpwd;

	oldpwd = find_env_var(env_list, "OLDPWD");
	if (!oldpwd || !oldpwd->value)
	{
		perror("cd: OLDPWD not set");
		return (NULL);
	}
	printf("%s\n", oldpwd->value);
	return (oldpwd);
}

char	*while_cd_add(char *new_home, char *home_value, char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (home_value[i])
	{
		new_home[i] = home_value[i];
		i++;
	}
	while (path[j])
	{
		new_home[i] = path[j];
		j++;
		i++;
	}
	new_home[i] = '\0';
	return (new_home);
}

char	*cd_add(t_env *env_list, char *path)
{
	char	*new_home;
	int		size;
	t_env	*home;

	home = find_env_var(env_list, "HOME");
	if (!home || !home->value)
	{
		perror("cd: HOME not set");
		return (NULL);
	}
	size = ft_strlen(home->value) + ft_strlen(path);
	new_home = malloc(size);
	if (!new_home)
		return (NULL);
	new_home = while_cd_add(new_home, home->value, path);
	return (new_home);
}

bool	verif_env(t_cmd *command, t_data *data)
{
	if (command->arg[1])
	{
		ft_putstr_fd("Trop d'arguments\n", 2);
		data->return_value = 127;
		return (true);
	}
	ft_env(data->envp, command->fd_out);
	data->return_value = 0;
	return (true);
}

bool	verif_pwd(t_cmd *command, t_data *data)
{
	data->return_value = 1;
	if (verif_option(command->arg[1]))
		ft_putstr_fd("option non prise en compte\n", 2);
	else
	{
		ft_pwd(command->fd_out);
		data->return_value = 0;
	}
	return (true);
}
