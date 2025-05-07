/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:00:46 by fparet            #+#    #+#             */
/*   Updated: 2025/03/20 03:14:15 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "free_etc.h"

void	ft_unset(t_env **env_list, char *key)
{
	t_env	*current;
	t_env	*prev;
	int		len;

	current = *env_list;
	prev = NULL;
	len = ft_strlen(key);
	while (current)
	{
		if (ft_strncmp(current->key, key, len + 1) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env_list = current->next;
			ft_free(current->key);
			ft_free(current->value);
			ft_free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
