/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 04:08:31 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 20:11:47 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

# include "minishell.h"

int		check_here(t_token *token);
int		check_append(t_token *token);
int		check_out(t_token *token);
int		check_in(t_token *token);
int		check_pipe(t_token *token);

char	*get_type(t_type type);

void	errno_exit(t_data *data);
void	errno_error(t_data *data);

#endif