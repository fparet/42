/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 03:59:02 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/22 11:18:17 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"
#include "env_list.h"
#include "exec.h"
#include "free_etc.h"
#include "signaux.h"

void	process(t_data *data, t_tmp *tmp)
{
	if (data->commands[tmp->i]->cmd == NULL)
	{
		close_data(data, tmp->fd);
		ft_free(tmp->process_ids);
		write(2, data->commands[tmp->i]->arg[0],
			ft_strlen(data->commands[tmp->i]->arg[0]));
		write(2, ": command not found\n", 20);
		ft_free(tmp);
		errno_exit(data);
	}
	if (dup2(data->commands[tmp->i]->fd_in, STDIN_FILENO) == -1
		|| dup2(data->commands[tmp->i]->fd_out, STDOUT_FILENO) == -1)
	{
		close_data(data, tmp->fd);
		ft_free(tmp->process_ids);
		ft_free(tmp);
		perror(NULL);
		errno_exit(data);
	}
	close_data(data, tmp->fd);
	execve(data->commands[tmp->i]->cmd, data->commands[tmp->i]->arg, data->env);
	perror(data->commands[tmp->i]->arg[0]);
	ft_free(tmp->process_ids);
	ft_free(tmp);
	errno_exit(data);
}

int	wait_function(t_data *data, int *process_ids, bool last_isbuiltin)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (data->cmd > 0)
	{
		while (i < data->cmd)
		{
			if (waitpid(process_ids[i++], &status, 0) == -1)
			{
				if (errno != EINTR)
				{
					perror("waitpid");
					ft_free(process_ids);
					return (-1);
				}
			}
		}
	}
	if (last_isbuiltin == false && WIFEXITED(status))
		data->return_value = WEXITSTATUS(status);
	return (0);
}

int	core_process(t_data *data, t_tmp *tmp)
{
	if (data->nb_pipes > 0 && tmp->i < data->nb_pipes)
		if (setup_pipe_fds(data, tmp->i, &tmp->fd))
			return (ft_free(tmp->process_ids), -2);
	if (data->commands[tmp->i]->arg && ft_verif_bultins(data->commands[tmp->i],
			data) == false)
	{
		signal_change(2);
		if (ft_strncmp(data->commands[tmp->i]->arg[0], "./minishell", 12) == 0)
			signal(SIGINT, exception);
		tmp->process_ids[tmp->j] = fork();
		if (tmp->process_ids[tmp->j] == -1)
			return (ft_free(tmp->process_ids), -3);
		if (tmp->process_ids[(tmp->j)++] == 0)
			process(data, tmp);
	}
	close_pipes(data, tmp->i, &tmp->fd);
	(tmp->i)++;
	return (0);
}

void	verif_if_exit_is_last_cmd(t_data *data, bool *last_isbuiltin)
{
	int	i;

	i = 0;
	if (!data->commands[i]->arg)
		return ;
	while (data->commands[i + 1])
		i++;
	if (ft_verif_is_bultins(data->commands[i]) == true)
		*last_isbuiltin = true;
	else
		*last_isbuiltin = false;
}

int	execute(t_data *data)
{
	t_tmp	*tmp;
	bool	last_isbuiltin;

	last_isbuiltin = false;
	tmp = setup_tmp(data);
	if (!tmp)
		return (-1);
	while (data->commands[tmp->i])
	{
		if (core_process(data, tmp))
			return (ft_free(tmp->process_ids), ft_free(tmp), -2);
	}
	free_fd_redir(data->fd_redirections, data->fd_redir_size);
	verif_if_exit_is_last_cmd(data, &last_isbuiltin);
	if (wait_function(data, tmp->process_ids, last_isbuiltin) < 0)
		return (-1);
	setup_signals();
	ft_free(tmp->process_ids);
	ft_free(tmp);
	return (0);
}
