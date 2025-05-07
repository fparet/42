/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:23:41 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/22 11:14:22 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signaux.h"

void	exception(int sig)
{
	if (sig == SIGINT)
		g_signal_received = 130;
}

void	save_terminal_settings(t_data *data)
{
	if (tcgetattr(STDIN_FILENO, &data->orig_term) == -1)
		perror("tcgetattr");
}

void	disable_echoctl(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		return ;
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		perror("tcsetattr");
}

void	restore_terminal_settings(t_data *data)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->orig_term) == -1)
		perror("tcsetattr");
}
