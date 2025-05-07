/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_etc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:27:19 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:06:41 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_ETC_H
# define FREE_ETC_H

# include "minishell.h"

void	free_command(t_cmd **commands);
void	free_pipe(int (*tab)[2], int nb_pipes);
void	free_fd_redir(int *tab, int size);
void	free_data(t_data *data);
void	next_line(t_data *data);
void	ft_free(void *ptr);
void	ft_close(int fd);

#endif