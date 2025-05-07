/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:11:18 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:24:11 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "free_etc.h"

void	free_list(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->next;
		if (token->value)
			ft_free(token->value);
		ft_free(token);
		token = tmp;
	}
}

t_token	*new_token(t_type type, t_state state, char *value, bool space)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->index = 1;
	new->var = false;
	new->type = type;
	new->state = state;
	new->space = space;
	if (value)
		new->value = ft_strdup(value);
	else
		new->value = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	add_token(t_token **token, t_token *new)
{
	t_token	*tmp;
	int		i;

	i = 1;
	if (!new)
		return (1);
	if (!*token)
		*token = new;
	else
	{
		tmp = *token;
		while (tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
		tmp->index = i;
	}
	return (0);
}

int	count_quote(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '"' || str[i] == '\'')
			count++;
	}
	return (count);
}

void	copy_inner_quote_content(char *str, char *tmp, int *i, int *j)
{
	char	quote;

	quote = str[(*i)];
	(*i)++;
	while (str[(*i)] && str[(*i)] != quote)
		tmp[(*j)++] = str[(*i)++];
	if (str[(*i)] == quote)
		i++;
}
