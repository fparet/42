/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:45:15 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/24 15:40:00 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_etc.h"
#include "var_env.h"

char	*add_var(char *line, int *j, char *var, char c)
{
	int	i;

	i = 0;
	if (c == '?' && !var)
		return (NULL);
	if (!var)
		return (line);
	while (var && var[i])
		line[(*j)++] = var[i++];
	if (c == '?' || c == '$')
		ft_free(var);
	return (line);
}

char	*check_env(char *str, t_data *data)
{
	int	i;
	int	itmp;

	i = 0;
	itmp = 0;
	if (str[0] == '?')
		return (ft_itoa(data->return_value));
	if (str[0] == '$')
		return (get_pid());
	while (str[itmp] && (ft_isalnum(str[itmp]) || str[itmp] == '_'))
		itmp++;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], str, itmp) == 0
			&& (data->env[i][itmp]) == '=')
			return (data->env[i] + itmp + 1);
		i++;
	}
	return (0);
}

int	check_var(char *str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!data->env || !str)
		return (ft_strlen(str));
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			i++;
			j += ft_strlenvar(check_env(&str[i], data), str[i]);
			if (str[i] == '?' || str[i] == '$')
				i++;
			else
				while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
					i++;
		}
		else
			increment_both(&i, &j);
	}
	return (j);
}

int	expand_token_var(t_data *data, char *str, char **line, bool *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			if (var)
				*var = true;
			i++;
			*line = add_var(*line, &j, check_env(&str[i], data), str[i]);
			if (!(*line))
				return (-1);
			if (str[i] == '?' || str[i] == '$')
				i++;
			else
				while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
					i++;
		}
		else
			(*line)[j++] = str[i++];
	}
	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	int		len;
// 	char	*line;
// 	char	*str;
// 	bool	var;

// 	str = ft_strdup("oui $PWD");
// 	len = check_var(str, env);
// 	line = ft_calloc(len + 1, sizeof(char));
// 	if (!line)
// 		return (1);
// 	if (expand_token_var(env, str, &line, 0))
// 		return (free(line), 1);
// 	printf("%s\n", line);
// }
