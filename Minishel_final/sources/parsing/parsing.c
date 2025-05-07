/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:09:44 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/23 14:01:32 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"
#include "commands.h"
#include "parsing.h"
#include "token.h"
#include "var_env.h"
#include "free_etc.h"

int	check_token(t_data *data, int count)
{
	t_token	*tmp;

	tmp = data->token;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		if (tmp->type == PIPE)
			count += check_pipe(tmp);
		if (tmp->type == IN)
			count += check_in(tmp);
		if (tmp->type == OUT)
			count += check_out(tmp);
		if (tmp->type == APPEND)
			count += check_append(tmp);
		if (tmp->type == HERE)
			count += check_here(tmp);
		tmp = tmp->next;
		if (count)
		{
			data->return_value = 2;
			break ;
		}
	}
	return (count);
}

int	have_a_cmd(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->prev)
		tmp = tmp->prev;
	else
		return (1);
	while (tmp)
	{
		if (tmp->type == CMD)
			return (0);
		if (tmp->type == PIPE)
			return (1);
		tmp = tmp->prev;
	}
	return (1);
}

void	redefine_token_types(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		if (tmp->next && tmp->next->type == CMD && (tmp->type == IN
				|| tmp->type == OUT || tmp->type == APPEND))
			tmp->next->type = FILES;
		if (tmp->next && tmp->type == HERE && tmp->next->type == CMD)
			tmp->next->type = LIM;
		if (tmp->type == CMD && !have_a_cmd(tmp))
			tmp->type = ARG;
		tmp = tmp->next;
	}
}

int	parse_var(t_data *data)
{
	t_token	*tmp;
	char	*line;
	int		len;

	if (!data->env || !data->token)
		return (0);
	tmp = data->token;
	while (tmp)
	{
		if (tmp->type == CMD && tmp->state != QUOTE)
		{
			len = check_var(tmp->value, data);
			line = ft_calloc(len + 1, sizeof(char));
			if (!line)
				return (-1);
			if (expand_token_var(data, tmp->value, &line, &tmp->var))
				return (-1);
			if (tmp->value)
				ft_free(tmp->value);
			tmp->value = line;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	parsing(t_data *data)
{
	int	count;

	count = 0;
	if (parse_token(data))
	{
		perror("malloc error");
		return (errno_error(data), 1);
	}
	if (concat_token(data))
	{
		perror("");
		return (errno_error(data), 1);
	}
	if (parse_var(data))
	{
		perror("malloc error");
		return (errno_error(data), 2);
	}
	if (check_token(data, count))
		return (3);
	redefine_token_types(data);
	if (build_tab_exe(data))
		return (4);
	return (0);
}
