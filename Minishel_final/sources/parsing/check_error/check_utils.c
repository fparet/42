/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:56:02 by igrousso          #+#    #+#             */
/*   Updated: 2025/02/22 04:29:05 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"

char	*get_type(t_type type)
{
	if (type == PIPE)
		return ("`|'\n");
	if (type == IN)
		return ("`<'\n");
	if (type == OUT)
		return ("`>'\n");
	if (type == APPEND)
		return ("`>>'\n");
	if (type == HERE)
		return ("`<<'\n");
	if (type == END)
		return ("`newline'\n");
	return (NULL);
}
