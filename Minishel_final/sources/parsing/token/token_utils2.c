/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:46:22 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/21 11:41:53 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	exception_token(char *str, int i)
{
	if (str[i] == '$')
	{
		if (str[i + 1] == '\0')
			return (0);
		if (str[i + 1] == '"' || str[i + 1] == '\'')
			return (1);
	}
	return (0);
}

int	parse_token(t_data *data)
{
	int		i;
	int		count_fail;
	char	*str;

	i = 0;
	count_fail = 0;
	str = data->line;
	while (str[i])
	{
		if (str[i] == ' ' || exception_token(str, i))
			i++;
		else if (str[i] == '|')
			count_fail += pipe_token(data, &i);
		else if ((str[i] == '<' || str[i] == '>'))
			count_fail += redir_token(data, &i);
		else if (str[i] == 39)
			count_fail += quote_token(data, &i, str);
		else if (str[i] == '"')
			count_fail += d_quote_token(data, &i, str);
		else
			count_fail += cmd_token(data, &i, str);
	}
	count_fail += add_token(&data->token, new_token(END, NOTHING, NULL, false));
	return (count_fail);
}
