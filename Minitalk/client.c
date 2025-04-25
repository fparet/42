/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:36:33 by fparet            #+#    #+#             */
/*   Updated: 2024/11/22 15:36:35 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (str[i] - 48) + nb;
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			nb = nb * 10;
		i++;
	}
	if ((j % 2) == 1)
		nb = -nb;
	return (nb);
}

int	send_bits(char c, pid_t server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> (7 - i)) & 1)
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				write(1, "erreur SIGUSR2", 14);
				return (1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				write(1, "erreur SIGUSR1", 14);
				return (1);
			}
		}
		i++;
		usleep(2500);
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(1, "Parametres incorrects: ", 23);
		write(1, "av[1]: <PID> serveur, av[2]: texte a envoyer.\n", 46);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		write(1, "Erreur : PID invalide.\n", 23);
		return (1);
	}
	while (av[2][i])
	{
		send_bits(av[2][i], server_pid);
		i++;
	}
	send_bits('\0', server_pid);
	write(1, "Signal envoye !\n", 17);
	return (0);
}
