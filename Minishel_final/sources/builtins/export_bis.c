/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:06:03 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 11:06:06 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "free_etc.h"

void	print_exported_variables(t_env *env_list)
{
	t_env	*current;

	if (env_list)
	{
		current = env_list;
		while (current)
		{
			printf("declare -x %s=\"%s\"\n", current->key, current->value);
			current = current->next;
		}
	}
}

char	*get_key(char *arg)
{
	char		*key;
	size_t		i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
	{
		key = malloc(i + 1);
		if (!key)
			return (NULL);
		ft_strlcpy(key, arg, i + 1);
		return (key);
	}
	return (NULL);
}

char	*get_value(char *arg)
{
	char		*value;
	size_t		i;
	size_t		len;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=')
	{
		len = ft_strlen(arg) - i - 1;
		value = malloc(len + 1);
		if (!value)
			return (NULL);
		ft_strlcpy(value, arg + i + 1, len + 1);
		return (value);
	}
	return (NULL);
}
