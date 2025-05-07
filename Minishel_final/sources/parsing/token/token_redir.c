/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:20:03 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/07 18:12:20 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	pipe_token(t_data *data, int *i)
{
	bool	count;
	int		count_fail;

	count_fail = 0;
	if (*i >= 1 && data->line[*i - 1] == ' ')
		count = true;
	else
		count = false;
	count_fail += add_token(&data->token, new_token(PIPE, NOTHING, "|", count));
	(*i)++;
	return (count_fail);
}

int	in_here_token(t_data *data, int *i)
{
	bool	count;
	int		count_fail;

	count_fail = 0;
	if (*i >= 1 && data->line[*i - 1] == ' ')
		count = true;
	else
		count = false;
	if (data->line[*i + 1] == '<')
	{
		count_fail += add_token(&data->token, new_token(HERE, NOTHING, "<<",
					count));
		*i += 2;
	}
	else
	{
		count_fail += add_token(&data->token, new_token(IN, NOTHING, "<",
					count));
		(*i)++;
	}
	return (count_fail);
}

int	out_append_token(t_data *data, int *i)
{
	bool	count;
	int		count_fail;

	count_fail = 0;
	if (*i >= 1 && data->line[*i - 1] == ' ')
		count = true;
	else
		count = false;
	if (data->line[*i + 1] == '>')
	{
		count_fail += add_token(&data->token, new_token(APPEND, NOTHING, ">>",
					count));
		*i += 2;
	}
	else
	{
		count_fail += add_token(&data->token, new_token(OUT, NOTHING, ">",
					count));
		(*i)++;
	}
	return (count_fail);
}

int	redir_token(t_data *data, int *i)
{
	int	count_fail;

	count_fail = 0;
	if (data->line[*i] == '<')
		count_fail += in_here_token(data, i);
	else if (data->line[*i] == '>')
		count_fail += out_append_token(data, i);
	return (count_fail);
}
