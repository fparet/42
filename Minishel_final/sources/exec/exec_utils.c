/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:41:22 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 03:11:46 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "free_etc.h"

void	close_data(t_data *data, int fd[3])
{
	if (fd[0] != -1)
		ft_close(fd[0]);
	if (fd[1] != -2)
		ft_close(fd[1]);
	if (fd[2] != -3)
		ft_close(fd[2]);
	if (data->fd_redirections)
		free_fd_redir(data->fd_redirections, data->fd_redir_size);
}

int	setup_pipe_fds(t_data *data, int i, int (*fd)[3])
{
	if ((*fd)[0] != -1)
		(*fd)[2] = (*fd)[0];
	if (pipe(*fd))
		return (-2);
	if (data->commands[i]->fd_out == -11)
		data->commands[i]->fd_out = (*fd)[1];
	if (data->commands[i + 1] && data->commands[i + 1]->fd_in == -10)
		data->commands[i + 1]->fd_in = (*fd)[0];
	return (0);
}

void	close_pipes(t_data *data, int i, int (*fd)[3])
{
	if (data->commands[i]->fd_in == (*fd)[2]
		|| data->commands[i]->fd_in == (*fd)[0])
		ft_close(data->commands[i]->fd_in);
	if (data->commands[i]->fd_out == (*fd)[1])
		ft_close(data->commands[i]->fd_out);
}

t_tmp	*setup_tmp(t_data *data)
{
	t_tmp	*tmp;

	tmp = malloc(sizeof(t_tmp));
	if (!tmp)
		return (NULL);
	tmp->process_ids = malloc(data->cmd * sizeof(int));
	if (!tmp->process_ids)
		return (ft_free(tmp), NULL);
	tmp->i = 0;
	tmp->j = 0;
	tmp->fd[0] = -1;
	tmp->fd[1] = -2;
	tmp->fd[2] = -3;
	return (tmp);
}
