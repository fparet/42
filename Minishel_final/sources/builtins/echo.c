/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:48:03 by fparet            #+#    #+#             */
/*   Updated: 2025/03/13 23:22:55 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_list.h"
#include "free_etc.h"

bool	handle_n_option(char **args, int *index)
{
	bool	new_line;
	int		j;

	new_line = true;
	while (args[*index] && args[*index][0] == '-' && args[*index][1] == 'n')
	{
		j = 2;
		while (args[*index][j] && args[*index][j] == 'n')
			j++;
		if (args[*index][j] != '\0')
			break ;
		new_line = false;
		(*index)++;
	}
	return (new_line);
}

void	write_arguments(int fd, char **args, int index)
{
	while (args[index])
	{
		write(fd, args[index], ft_strlen(args[index]));
		if (errno == ENOSPC)
		{
			write(2, "echo: write error: No space left on device\n", 43);
			return ;
		}
		if (args[index + 1])
			write(fd, " ", 1);
		index++;
	}
}

void	ft_echo(char **args, int fd)
{
	int		i;
	bool	new_line;

	i = 1;
	if (fd == -1)
		return ;
	new_line = handle_n_option(args, &i);
	write_arguments(fd, args, i);
	if (new_line)
		write(fd, "\n", 1);
}
