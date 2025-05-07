/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 01:00:27 by fparet            #+#    #+#             */
/*   Updated: 2025/03/13 23:23:33 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "free_etc.h"

t_env	*ft_envnew(void *content)
{
	t_env	*new_node;
	char	*eq_pos;
	size_t	key_len;

	eq_pos = ft_strchr((char *)content, '=');
	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = NULL;
	new_node->value = NULL;
	if (eq_pos)
	{
		key_len = eq_pos - (char *)content;
		new_node->key = malloc(key_len + 1);
		if (!new_node->key)
			return (NULL);
		ft_strlcpy(new_node->key, content, key_len + 1);
		new_node->value = ft_strdup(eq_pos + 1);
		if (!new_node->value)
			return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

void	ft_addback(t_env **lst, t_env *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else if ((*lst)->next)
		(ft_addback(&(*lst)->next, new));
	else
	{
		(*lst)->next = new;
		return ;
	}
}

int	ft_replace_env(t_env *current, char *value)
{
	ft_free(current->value);
	current->value = ft_strdup(value);
	if (!current->value)
	{
		perror("Memory allocation failed in ft_add_env");
		return (0);
	}
	return (1);
}

void	ft_add_env(t_env **env, char *key, char *value)
{
	t_env	*current;
	t_env	*new_node;

	if (!env || !key || !value)
		return ;
	current = *env;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			if (!ft_replace_env(current, value))
				return ;
			return ;
		}
		current = current->next;
	}
	new_node = create_env_node(key, value);
	if (!new_node)
		return ;
	ft_addback(env, new_node);
}

void	ft_export(t_env **env, char *arg)
{
	char	*key;
	char	*value;

	key = get_key(arg);
	value = get_value(arg);
	ft_add_env(env, key, value);
	ft_free(key);
	ft_free(value);
}
/*
char *replace_value(t_env **env, char *arg)
{
	t_env *current;
	char *value;
	char *new_value;
	int i;
	int j;

	current = *env;
	while (current)
	{
		if (strcmp(current->key, get_key(arg)) == 0)
		{
			value = get_value(arg);
			new_value = malloc(ft_strlen(value) + ft_strlen(current->value) + 1);
			if (!new_value)
				return (NULL);
			i = 0;
			while (current->value[i])
			{
				new_value[i] = current->value[i];
				i++;
			}
			j = 0;
			while (value[j])
			{
				new_value[i + j] = value[j];
				j++;
			}
			new_value[i + j] = '\0';
			return (new_value);
		}
		current = current->next;
	}
	return (NULL);
}

void	ft_export_plus(t_env **env, char *arg)
{
	char	*new_value;
	t_env	*current;

	current = *env;
	while (current)
	{
		if (strcmp(current->key, get_key(arg)) == 0)
		{
			new_value = replace_value(env, arg);
			if (!new_value)
				return ;
			free(current->value);
			current->value = new_value;
			return ;
		}
		current = current->next;
	}
}
	
void	ft_export_plus(t_env **env, char *arg)
{
	char *		new_value;
	t_env	*current;

	current = *env;
	new_value = replace_value(env, arg);
	free(current->value);
	current->value = new_value;
	ft_free(new_value);
}
*/