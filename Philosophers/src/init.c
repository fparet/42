/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:38:41 by fparet            #+#    #+#             */
/*   Updated: 2025/05/31 15:38:45 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_mutexes(t_data *data)
{
	int i;

	if (pthread_mutex_init(&data->simulation_lock, NULL) != 0)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (!data->forks)
		return (1);
	i = -1;
	while (++i < data->num_philosophers)
	if (pthread_mutex_init(&data->forks[i], NULL))
		return (1);
	if (pthread_mutex_init(&data->print_lock, NULL))
		return (1);
	return (0);
}
/*
int init_philosophers(t_data *data) 
{
	int i;
	pthread_mutex_init(&data->philosophers[i].meal_lock, NULL);
	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
	if (!data->philosophers)
		return (1);
	i = -1;
	while (++i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].last_meal_time = 0;
		data->philosophers[i].data = data;
	}
	return (0);
}
*/

int	init_philosophers(t_data *data)
{
	int i;

	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
	if (!data->philosophers)
		return (1);
	i = -1;
	while (++i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].data = data;
		if (pthread_mutex_init(&data->philosophers[i].meal_lock, NULL))
			return (1);
	}
	return (0);
}

int init_data(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	data->num_philosophers = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->max_meals = atoi(argv[5]);
	else
		data->max_meals = -1;
	set_simulation_end(data, 0);
	if (init_mutexes(data) || init_philosophers(data))
		return (1);
	data->start_time = get_time();
	return (0);
}

