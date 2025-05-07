/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:41:07 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/22 14:39:02 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_etc.h"
#include "token.h"

int	concat(t_token *token, t_token *token_next)
{
	token->value = ft_strjoinfree(token->value, token_next->value);
	if (!token->value)
		return (1);
	ft_free(token_next->value);
	token->next = token_next->next;
	token->next->prev = token;
	ft_free(token_next);
	token->value = remove_quote(token->value);
	if (!token->value)
		return (2);
	token->state = NOTHING;
	return (0);
}

void	redifine_index_token(t_data *data)
{
	int		i;
	t_token	*tmp;

	i = 1;
	tmp = data->token;
	while (tmp->type != END)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}

int	concat_token(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp->type != END)
	{
		if (tmp->next->space == false && tmp->next->type == CMD
			&& tmp->type == CMD)
			if (concat(tmp, tmp->next))
				return (1);
		tmp = tmp->next;
	}
	redifine_index_token(data);
	return (0);
}
