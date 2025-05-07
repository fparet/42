/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:45:42 by fparet            #+#    #+#             */
/*   Updated: 2025/01/15 20:45:44 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

void	ft_pwd(int fd)
{
	char	cdir[PATH_MAX];

	if (getcwd(cdir, PATH_MAX) != NULL)
	{
		ft_putstr_fd(cdir, fd);
		write(fd, "\n", 1);
	}
	else
		perror("pwd error");
}
