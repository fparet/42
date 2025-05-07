/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:13:54 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:23:59 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "free_etc.h"

int	check_access(char *tab_path, char *command, char **command_path)
{
	char	*temp;

	temp = ft_strjoin(tab_path, "/");
	if (!temp)
		return (-1);
	*command_path = ft_strjoin(temp, command);
	ft_free(temp);
	if (!*command_path)
		return (-2);
	if (access(*command_path, F_OK) == 0 && access(*command_path, X_OK) == 0)
		return (0);
	ft_free(*command_path);
	return (1);
}

char	*check_path(char *command, char *path)
{
	char	**tab_path;
	int		i;
	char	*command_path;
	int		res;

	tab_path = ft_split(path, ':');
	if (!tab_path)
		return (NULL);
	i = 0;
	while (tab_path[i])
	{
		res = check_access(tab_path[i], command, &command_path);
		if (res < 0)
			return (free_tab(tab_path), NULL);
		else if (res == 0)
			return (free_tab(tab_path), command_path);
		i++;
	}
	free_tab(tab_path);
	return (NULL);
}

char	*get_path(char *command, char **env)
{
	int		i;
	char	*command_path;

	i = 0;
	command_path = NULL;
	if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
		return (ft_strdup(command));
	if (!env)
		return (ft_strdup(command));
	if (command[0] == '/')
		return (ft_strdup(command));
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			command_path = check_path(command, env[i] + 5);
		i++;
	}
	return (command_path);
}

// int	main(int ac, char **av, char **env)
// {
// 	char	*str;

// 	(void)ac;
// 	if (access(av[1], X_OK) == 0)
// 	{
// 		printf("%s\n", av[1]);
// 		return (0);
// 	}
// 	str = get_path(av[1], env);
// 	if (!str)
// 		printf("not executable\n");
// 	else
// 		printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
