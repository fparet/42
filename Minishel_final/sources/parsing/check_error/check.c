/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:26:11 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/07 17:55:04 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"

int	check_pipe(t_token *token)
{
	if (!token->prev || !token->next || token->next->type == END)
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putstr_fd(get_type(token->type), 2);
		return (1);
	}
	if (token->next->type == PIPE)
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putstr_fd(get_type(token->next->type), 2);
		return (1);
	}
	return (0);
}

int	check_in(t_token *token)
{
	if (token->next->type == PIPE || token->next->type == OUT
		|| token->next->type == APPEND || token->next->type == HERE
		|| token->next->type == IN || token->next->type == END)
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putstr_fd(get_type(token->next->type), 2);
		return (1);
	}
	return (0);
}

int	check_out(t_token *token)
{
	if (token->next->type == PIPE || token->next->type == OUT
		|| token->next->type == APPEND || token->next->type == HERE
		|| token->next->type == IN || token->next->type == END)
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putstr_fd(get_type(token->next->type), 2);
		return (1);
	}
	return (0);
}

int	check_append(t_token *token)
{
	if (token->next->type == PIPE || token->next->type == OUT
		|| token->next->type == APPEND || token->next->type == HERE
		|| token->next->type == IN || token->next->type == END)
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putstr_fd(get_type(token->next->type), 2);
		return (1);
	}
	return (0);
}

int	check_here(t_token *token)
{
	if (token->next->type == PIPE || token->next->type == OUT
		|| token->next->type == APPEND || token->next->type == HERE
		|| token->next->type == IN || token->next->type == END)
	{
		ft_putstr_fd("syntax error near unexpected token ", 2);
		ft_putstr_fd(get_type(token->next->type), 2);
		return (1);
	}
	return (0);
}
