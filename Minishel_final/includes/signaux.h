/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:50:09 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/22 11:15:23 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAUX_H
# define SIGNAUX_H

# include "minishell.h"
# include <termios.h>

void	signal_handler(int sig);
void	signal_here(int sig);
void	signal_fork(int sig);
void	signal_change(int state);
void	setup_signals(void);

void	exception(int sig);
void	restore_terminal_settings(t_data *data);
void	disable_echoctl(void);
void	save_terminal_settings(t_data *data);

#endif