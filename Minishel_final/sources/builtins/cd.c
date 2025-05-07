/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:59:55 by fparet            #+#    #+#             */
/*   Updated: 2025/03/24 15:39:54 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "free_etc.h"
#include "minishell.h"

t_env	*find_env_var(t_env *env_list, const char *key)
{
	while (env_list)
	{
		if (ft_strncmp(env_list->key, key, ft_strlen(key)) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

char	*get_cd_target(t_env *env_list, char *path, int *add)
{
	t_env	*home;
	t_env	*oldpwd;
	char	*home_bis;

	if (!path || ft_strncmp(path, "~", 2) == 0)
	{
		home = find_env_var(env_list, "HOME");
		if (!home || !home->value)
			return (perror("cd: HOME not set"), NULL);
		return (home->value);
	}
	if (ft_strncmp(path, "~", 1) == 0 && path[1])
	{
		home_bis = cd_add(env_list, path);
		*add = 1;
		return (home_bis);
	}
	if (ft_strncmp(path, "-", 2) == 0)
	{
		oldpwd = cd_tiret(env_list);
		return (oldpwd->value);
	}
	return (path);
}

void	update_env_var(t_env *env_list, char *key, char *value)
{
	t_env	*var;

	var = find_env_var(env_list, key);
	if (var)
	{
		ft_free(var->value);
		var->value = ft_strdup(value);
	}
	else
		ft_add_env(&env_list, key, value);
}

void	update_pwd(t_env *env_list)
{
	char	cwd[PATH_MAX];
	t_env	*oldpwd;

	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("getcwd");
		return ;
	}
	oldpwd = find_env_var(env_list, "PWD");
	if (oldpwd)
		update_env_var(env_list, "OLDPWD", oldpwd->value);
	update_env_var(env_list, "PWD", cwd);
}

void	ft_cd(t_env *env_list, char *path, t_data *data)
{
	int	cd_add;

	cd_add = 0;
	path = get_cd_target(env_list, path, &cd_add);
	if (!path)
		return ;
	if (chdir(path) == -1)
	{
		data->return_value = 1;
		perror("cd");
		return ;
	}
	if (cd_add == 1)
		ft_free(path);
	update_pwd(env_list);
	data->return_value = 0;
}
