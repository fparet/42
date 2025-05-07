/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_command_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:15:58 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 11:29:33 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"
#include "commands.h"
#include "env_list.h"
#include "signaux.h"

int	cmd_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr)
{
	data->commands[tmp->i]->cmd = get_path((*token_ptr)->value, data->env);
	data->commands[tmp->i]->arg = ft_calloc(ft_nb_args(*token_ptr) + 1,
			sizeof(char *));
	if (!data->commands[tmp->i]->arg)
	{
		perror("malloc error");
		errno_error(data);
		return (-1);
	}
	data->commands[tmp->i]->arg[tmp->j++] = (*token_ptr)->value;
	if (!ft_verif_is_bultins(data->commands[tmp->i]))
		data->cmd++;
	return (0);
}

int	in_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr)
{
	data->commands[tmp->i]->fd_in = open((*token_ptr)->next->value, O_RDONLY);
	if (data->commands[tmp->i]->fd_in == -1)
	{
		perror((*token_ptr)->next->value);
		errno_error(data);
		return (1);
	}
	data->fd_redirections[tmp->k++] = data->commands[tmp->i]->fd_in;
	return (0);
}

int	out_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr)
{
	if (check_file((*token_ptr)->next->value))
		data->commands[tmp->i]->fd_out = open((*token_ptr)->next->value,
				O_WRONLY | O_TRUNC, 0644);
	else
		data->commands[tmp->i]->fd_out = open((*token_ptr)->next->value,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->commands[tmp->i]->fd_out < 0)
	{
		perror((*token_ptr)->next->value);
		errno_error(data);
		return (1);
	}
	data->fd_redirections[tmp->k++] = data->commands[tmp->i]->fd_out;
	return (0);
}

int	here_fill_command(t_data *data, t_tmp *tmp, t_token **token)
{
	data->commands[tmp->i]->fd_in = create_here_doc_file((*token)->next->value,
			data);
	setup_signals();
	restore_terminal_settings(data);
	if (data->commands[tmp->i]->fd_in < 0)
	{
		if (g_signal_received == 0)
		{
			write(2, "Here_doc error\n", 15);
			data->return_value = 1;
		}
		else
			data->return_value = g_signal_received;
		return (-1);
	}
	data->fd_redirections[tmp->k++] = data->commands[tmp->i]->fd_in;
	return (0);
}

int	append_fill_command(t_data *data, t_tmp *tmp, t_token **token_ptr)
{
	if (check_file((*token_ptr)->next->value))
		data->commands[tmp->i]->fd_out = open((*token_ptr)->next->value,
				O_WRONLY | O_APPEND, 0644);
	else
		data->commands[tmp->i]->fd_out = open((*token_ptr)->next->value,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (data->commands[tmp->i]->fd_out < 0)
	{
		perror((*token_ptr)->next->value);
		errno_error(data);
		return (-1);
	}
	data->fd_redirections[tmp->k++] = data->commands[tmp->i]->fd_out;
	return (0);
}
