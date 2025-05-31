/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:38:41 by fparet            #+#    #+#             */
/*   Updated: 2025/05/31 15:38:45 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_data *data, int id, char *status)
{
	pthread_mutex_lock(&data->print_lock);
	if (!get_simulation_end(data))
		printf("%lld %d %s\n", get_time() - data->start_time, id, status);
	pthread_mutex_unlock(&data->print_lock);
}

void	cleanup(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philosophers)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->simulation_lock);
	free(data->forks);
	free(data->philosophers);
}

void	smart_sleep(int duration_ms, t_data *data)
{
	long long	start;
	int			ended;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(&data->simulation_lock);
		ended = data->simulation_end;
		pthread_mutex_unlock(&data->simulation_lock);
		if (ended || (get_time() - start >= duration_ms))
			break ;
		usleep(500);
	}
}

int	get_simulation_end(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->simulation_lock);
	value = data->simulation_end;
	pthread_mutex_unlock(&data->simulation_lock);
	return (value);
}

void	set_simulation_end(t_data *data, int value)
{
	pthread_mutex_lock(&data->simulation_lock);
	data->simulation_end = value;
	pthread_mutex_unlock(&data->simulation_lock);
}
