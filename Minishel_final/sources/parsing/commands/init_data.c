/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:18:35 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/15 00:51:16 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	fill_pipe_indexes(t_data *data)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = data->token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			i++;
		tmp = tmp->next;
	}
	data->nb_pipes = i;
	data->index_pipe = ft_calloc(i + 1, sizeof(int));
	if (!data->index_pipe)
		return (-1);
	tmp = data->token;
	i = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			data->index_pipe[i++] = tmp->index;
		tmp = tmp->next;
	}
	return (0);
}

int	*malloc_fd_redirections(t_data *data)
{
	int		i;
	int		*tab;
	t_token	*token;

	i = 0;
	token = data->token;
	while (token)
	{
		if (token->type == IN || token->type == OUT || token->type == APPEND
			|| token->type == HERE)
			i++;
		token = token->next;
	}
	data->fd_redir_size = i;
	tab = ft_calloc(i, sizeof(int));
	return (tab);
}

int	ft_nb_args(t_token *token)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = token;
	if (token->type == CMD)
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp && tmp->type != PIPE && tmp->type != END)
	{
		if (tmp->type == ARG)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	init_data2(t_data *data)
{
	if (fill_pipe_indexes(data) < 0)
		return (-1);
	data->fd_redirections = malloc_fd_redirections(data);
	if (!data->fd_redirections)
		return (-3);
	data->commands = ft_calloc(data->nb_pipes + 2, sizeof(t_cmd *));
	if (!data->commands)
		return (-4);
	return (0);
}
