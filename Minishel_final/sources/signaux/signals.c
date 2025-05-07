/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:48:47 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/20 10:48:47 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signaux.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_received = 130;
		write(2, "\n", 1);
		rl_replace_line("", 0);
		if (rl_on_new_line() != 0)
			return (perror("rl_on_new_line"));
		rl_redisplay();
	}
}

void	signal_here(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_received = 130;
		write(2, "\n", 1);
	}
}

void	signal_fork(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_received = 130;
		write(2, "\n", 1);
	}
	if (sig == SIGQUIT)
	{
		g_signal_received = 131;
		write(2, "Quit (core dumped)\n", 19);
	}
}

void	signal_change(int state)
{
	struct sigaction	here_ctrl;
	struct sigaction	here_ctrls;
	struct sigaction	fork;

	here_ctrl.sa_handler = signal_here;
	here_ctrls.sa_handler = SIG_IGN;
	fork.sa_handler = signal_fork;
	sigemptyset(&here_ctrl.sa_mask);
	sigemptyset(&here_ctrls.sa_mask);
	sigemptyset(&fork.sa_mask);
	here_ctrl.sa_flags = 0;
	here_ctrls.sa_flags = 0;
	fork.sa_flags = 0;
	if (state == 1)
	{
		sigaction(SIGINT, &here_ctrl, NULL);
		sigaction(SIGQUIT, &here_ctrls, NULL);
	}
	if (state == 2)
	{
		sigaction(SIGINT, &fork, NULL);
		sigaction(SIGQUIT, &fork, NULL);
	}
}

void	setup_signals(void)
{
	struct sigaction	ctrlc;
	struct sigaction	ctrlbs;

	ctrlc.sa_handler = signal_handler;
	ctrlbs.sa_handler = SIG_IGN;
	sigemptyset(&ctrlc.sa_mask);
	sigemptyset(&ctrlbs.sa_mask);
	ctrlc.sa_flags = 0;
	ctrlbs.sa_flags = 0;
	sigaction(SIGINT, &ctrlc, NULL);
	sigaction(SIGQUIT, &ctrlbs, NULL);
}
