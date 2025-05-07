/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:17:14 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 11:09:38 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "free_etc.h"

int	check_file(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	init_cmd(t_data *data, t_tmp *tmp)
{
	data->commands[tmp->i] = ft_calloc(1, sizeof(t_cmd));
	if (!data->commands[tmp->i])
		return (-1);
	data->commands[tmp->i]->fd_in = STDIN_FILENO;
	data->commands[tmp->i]->fd_out = STDOUT_FILENO;
	return (0);
}

void	pipe_fill_fd_command(t_data *data, t_tmp *tmp)
{
	if (data->nb_pipes > 0 && tmp->i - 1 >= 0
		&& data->commands[tmp->i]->fd_in == 0
		&& data->commands[tmp->i]->fd_out == 1)
		data->commands[tmp->i]->fd_in = -10;
	if (data->nb_pipes > 0 && tmp->i != data->nb_pipes
		&& data->commands[tmp->i]->fd_out == 1)
		data->commands[tmp->i]->fd_out = -11;
}

int	process_tokens(t_data *data, t_tmp *tmp, t_token **token_ptr)
{
	while ((*token_ptr)->index != data->index_pipe[tmp->i])
	{
		pipe_fill_fd_command(data, tmp);
		if ((*token_ptr)->type == CMD)
			if (cmd_fill_command(data, tmp, token_ptr))
				return (-1);
		if ((*token_ptr)->type == IN)
			if (in_fill_command(data, tmp, token_ptr))
				return (-2);
		if ((*token_ptr)->type == OUT)
			if (out_fill_command(data, tmp, token_ptr))
				return (-3);
		if ((*token_ptr)->type == ARG)
			data->commands[tmp->i]->arg[tmp->j++] = (*token_ptr)->value;
		if ((*token_ptr)->type == HERE)
			if (here_fill_command(data, tmp, token_ptr))
				return (-4);
		if ((*token_ptr)->type == APPEND)
			if (append_fill_command(data, tmp, token_ptr))
				return (-5);
		if ((*token_ptr)->type == END)
			break ;
		*token_ptr = (*token_ptr)->next;
	}
	return (0);
}

int	build_tab_exe(t_data *data)
{
	t_token	*token;
	t_tmp	*tmp;

	if (!data->token || init_data2(data))
		return (-1);
	tmp = malloc(sizeof(t_tmp));
	if (!tmp)
		return (-1);
	token = data->token;
	tmp->i = 0;
	tmp->k = 0;
	while (token)
	{
		if (init_cmd(data, tmp))
			return (-2);
		tmp->j = 0;
		if (process_tokens(data, tmp, &token))
			return (ft_free(tmp), free_fd_redir(data->fd_redirections,
					data->fd_redir_size), -3);
		if (tmp->i < data->nb_pipes + 1)
			tmp->i++;
		token = token->next;
	}
	ft_free(tmp);
	return (0);
}
