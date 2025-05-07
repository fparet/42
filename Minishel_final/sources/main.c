/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:12:18 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/24 15:05:26 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "exec.h"
#include "free_etc.h"
#include "minishell.h"
#include "parsing.h"
#include "signaux.h"
#include "token.h"

volatile sig_atomic_t	g_signal_received = 0;

char	**get_env_from_list(t_env *envp)
{
	t_env	*tmp;
	int		i;
	char	**env;

	tmp = envp;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	env = ft_calloc(i + 1, sizeof(char *));
	if (!env)
		return (NULL);
	tmp = envp;
	i = 0;
	while (tmp)
	{
		env[i] = ft_strjoinenv(tmp->key, tmp->value);
		if (!env[i])
			return (free_tab(env), NULL);
		tmp = tmp->next;
		i++;
	}
	return (env);
}

void	restart_data(t_data *data)
{
	data->line = NULL;
	data->token = NULL;
	data->commands = NULL;
	data->fd_redirections = NULL;
	data->index_pipe = NULL;
	data->nb_pipes = -1;
	data->cmd = 0;
	data->env = get_env_from_list(data->envp);
	if (!data->env)
		printf("Warning, env is empty !\n");
}

int	minishell_loop(t_data *data)
{
	g_signal_received = 0;
	restart_data(data);
	data->line = readline("\001\033[1;31m\002minishell: \001\033[0m\002");
	if (g_signal_received)
	{
		data->return_value = g_signal_received;
		g_signal_received = 0;
	}
	if (!data->line)
	{
		data->return_value = 0;
		return (1);
	}
	if (ft_strncmp(data->line, "\n", 2) == 0)
		return (next_line(data), 1);
	add_history(data->line);
	if (!parsing(data))
		execute(data);
	next_line(data);
	return (3);
}

t_data	*init_data(char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->token = NULL;
	data->return_value = 0;
	data->envp = init_env_list(env);
	data->exit = 0;
	return (data);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	int		m;
	int		return_value;

	(void)av;
	if (!isatty(STDIN_FILENO))
		return (1);
	setup_signals();
	if (ac > 1)
		return (write(2, "Wrong number of arguments\n", 26));
	data = init_data(env);
	save_terminal_settings(data);
	while (data->exit == 0)
	{
		m = minishell_loop(data);
		if (m == 1)
			break ;
		if (m == 2)
			continue ;
	}
	printf("exit\n");
	return_value = data->return_value;
	return (free_data(data), return_value);
}
