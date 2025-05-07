/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:17:45 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/23 14:05:16 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_etc.h"
#include "token.h"

int	quote_token(t_data *data, int *i, char *str)
{
	int	start;
	int	count;

	count = 0;
	(*i)++;
	start = *i;
	if (!str[*i])
	{
		(*i)++;
		count = get_cmd_token(data, start, *i, QUOTE);
	}
	else if (str[*i] == '\'')
	{
		if (str[++(*i)] && str[*i] == ' ')
			count = get_cmd_token(data, start, *i, QUOTE);
	}
	else if (str[*i])
	{
		while (str[*i] && str[*i] != '\'')
			(*i)++;
		count = get_cmd_token(data, start, *i, QUOTE);
		(*i)++;
	}
	return (count);
}

int	d_quote_token(t_data *data, int *i, char *str)
{
	int	start;
	int	count;

	count = 0;
	(*i)++;
	start = (*i);
	if (!str[(*i)])
	{
		(*i)++;
		count = get_cmd_token(data, start, *i, DQUOTE);
	}
	else if (str[(*i)] == '"')
	{
		if (str[++(*i)] && str[(*i)] == ' ')
			count = get_cmd_token(data, start, *i - 1, DQUOTE);
	}
	else if (str[(*i)])
	{
		while (str[(*i)] && str[(*i)] != '"')
			(*i)++;
		count = get_cmd_token(data, start, *i, DQUOTE);
		(*i)++;
	}
	return (count);
}

char	*remove_quote(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str || count_quote(str) == 0)
		return (str);
	tmp = ft_calloc(ft_strlen(str) - count_quote(str) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			copy_inner_quote_content(str, tmp, &i, &j);
		else
			tmp[j++] = str[i++];
	}
	ft_free(str);
	return (tmp);
}

int	get_cmd_token(t_data *data, int start, int i, t_state state)
{
	char	*cmd;
	int		count;
	bool	space;
	int		j;

	j = 2;
	if (state == NOTHING)
		j = 1;
	if (start > j - 1 && (data->line[start - j] == ' ' || ((state == QUOTE
					|| state == DQUOTE) && data->line[start - j] == '$')))
		space = true;
	else
		space = false;
	cmd = ft_strndup(&data->line[start], i - start);
	if (state == NOTHING)
		cmd = remove_quote(cmd);
	if (!cmd)
		return (1);
	count = 0;
	count += add_token(&data->token, new_token(CMD, state, cmd, space));
	ft_free(cmd);
	return (count);
}

int	cmd_token(t_data *data, int *i, char *str)
{
	int		start;
	char	quote;
	int		itmp;

	start = (*i);
	while (str[(*i)] && ft_strchr("|<> ", str[(*i)]) == 0)
	{
		if (str[(*i)] == '"' || str[(*i)] == '\'')
		{
			itmp = (*i);
			quote = str[(*i)];
			(*i)++;
			while (str[(*i)] && str[(*i)] != quote)
				(*i)++;
			if (str[(*i)] == quote)
				(*i)++;
			else
				(*i) = itmp + 1;
		}
		else
			(*i)++;
	}
	return (get_cmd_token(data, start, *i, NOTHING));
}
