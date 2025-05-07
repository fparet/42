/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:28:50 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 02:55:55 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

typedef struct s_tmp
{
	int	i;
	int	j;
	int	fd[3];
	int	*process_ids;
}		t_tmp;

void	process(t_data *data, t_tmp *tmp);
int		wait_function(t_data *data, int *process_ids, bool exit_last);
int		core_process(t_data *data, t_tmp *tmp);
int		execute(t_data *data);

void	close_data(t_data *data, int fd[3]);
int		setup_pipe_fds(t_data *data, int i, int (*fd)[3]);
void	close_pipes(t_data *data, int i, int (*fd)[3]);
t_tmp	*setup_tmp(t_data *data);

#endif