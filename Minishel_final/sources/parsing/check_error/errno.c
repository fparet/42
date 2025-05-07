/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:25:27 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 20:12:14 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"
#include "free_etc.h"

void	errno_error(t_data *data)
{
	if (errno == ENOENT)
		data->return_value = 127;
	else if (errno == EACCES)
		data->return_value = 126;
	else if (errno == EPIPE)
		data->return_value = 141;
	else
		data->return_value = EXIT_FAILURE;
}

void	errno_exit(t_data *data)
{
	free_data(data);
	if (errno == ENOENT)
		exit(127);
	else if (errno == EACCES)
		exit(126);
	else if (errno == EPIPE)
		exit(141);
	else
		exit(EXIT_FAILURE);
}
