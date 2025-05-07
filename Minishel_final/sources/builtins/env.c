/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:23:16 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:23:26 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "free_etc.h"

t_env	*create_env_node(char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = NULL;
	node->next = NULL;
	return (node);
}

static	t_env	*add_env_node(t_env *head, char *key, char *value)
{
	t_env	*node;
	t_env	*current;

	node = create_env_node(key, value);
	ft_free(key);
	ft_free(value);
	if (!node)
		return (NULL);
	if (!head)
		return (node);
	current = head;
	while (current->next)
		current = current->next;
	current->next = node;
	return (head);
}

t_env	*init_env_list(char **envp)
{
	t_env	*head;
	char	*equal_sign;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		equal_sign = ft_strchr(envp[i], '=');
		if (equal_sign)
		{
			key = ft_strndup(envp[i], equal_sign - envp[i]);
			value = ft_strdup(equal_sign + 1);
			head = add_env_node(head, key, value);
			if (!head)
				return (NULL);
		}
		i++;
	}
	return (head);
}

void	free_env_list(t_env *env_list)
{
	t_env	*tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;
		if (tmp->key)
			ft_free(tmp->key);
		if (tmp->value)
			ft_free(tmp->value);
		ft_free(tmp);
	}
}

void	ft_env(t_env *env_list, int fd)
{
	while (env_list)
	{
		if (env_list->value)
		{
			ft_putstr_fd(env_list->key, fd);
			write(fd, "=", 1);
			ft_putstr_fd(env_list->value, fd);
			write(fd, "\n", 1);
		}
		env_list = env_list->next;
	}
}
