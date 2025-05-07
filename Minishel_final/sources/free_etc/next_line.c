/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:27 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 05:17:06 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "free_etc.h"
#include "token.h"

void	free_command(t_cmd **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		ft_free(commands[i]->cmd);
		ft_free(commands[i]->arg);
		ft_free(commands[i++]);
	}
	ft_free(commands);
}

void	free_pipe(int (*tab)[2], int nb_pipes)
{
	int	i;

	i = 0;
	while (i < nb_pipes)
	{
		if (tab[i][0] > 2)
			ft_close(tab[i][0]);
		if (tab[i][1] > 2)
			ft_close(tab[i][1]);
		i++;
	}
	ft_free(tab);
}

void	free_fd_redir(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > 2)
			ft_close(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	free_data(t_data *data)
{
	next_line(data);
	if (data->envp)
		free_env_list(data->envp);
	if (data)
		ft_free(data);
	rl_clear_history();
}

void	next_line(t_data *data)
{
	if (data->line)
	{
		ft_free(data->line);
		data->line = NULL;
	}
	if (data->token)
	{
		free_list(data->token);
		data->token = NULL;
	}
	if (data->commands)
	{
		free_command(data->commands);
		data->commands = NULL;
	}
	if (data->index_pipe)
	{
		free(data->index_pipe);
		data->index_pipe = NULL;
	}
	if (data->env)
	{
		free_tab(data->env);
		data->env = NULL;
	}
}
