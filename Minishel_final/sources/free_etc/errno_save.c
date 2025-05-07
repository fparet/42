/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:03:52 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:06:16 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_etc.h"

void	ft_free(void *ptr)
{
	int	tmp;

	tmp = errno;
	free(ptr);
	errno = tmp;
}

void	ft_close(int fd)
{
	int	tmp;

	tmp = errno;
	close(fd);
	errno = tmp;
}
