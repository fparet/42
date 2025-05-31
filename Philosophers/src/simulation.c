/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:38:41 by fparet            #+#    #+#             */
/*   Updated: 2025/05/31 15:38:45 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	handle_single_philosopher(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->forks[0]);
	print_status(philo->data, philo->id, "has taken a fork");
	smart_sleep(philo->data->time_to_die, philo->data);
	print_status(philo->data, philo->id, "died");
	pthread_mutex_unlock(&philo->data->forks[0]);
	set_simulation_end(philo->data, 1);
}

void	take_forks(t_philosopher *philo, int first_fork, int second_fork)
{
	pthread_mutex_lock(&philo->data->forks[first_fork]);
	print_status(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[second_fork]);
	print_status(philo->data, philo->id, "has taken a fork");
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	print_status(philo->data, philo->id, "is eating");
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_lock);
	smart_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
}

void	sleep_and_think(t_philosopher *philo, int first_fork, int second_fork)
{
	pthread_mutex_unlock(&philo->data->forks[second_fork]);
	pthread_mutex_unlock(&philo->data->forks[first_fork]);
	print_status(philo->data, philo->id, "is sleeping");
	smart_sleep(philo->data->time_to_sleep, philo->data);
	print_status(philo->data, philo->id, "is thinking");
}

void	whileroutine(t_philosopher *philo, int first_fork, int second_fork)
{
	print_status(philo->data, philo->id, "is thinking");
	take_forks(philo, first_fork, second_fork);
	eat(philo);
	sleep_and_think(philo, first_fork, second_fork);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	int				first_fork;
	int				second_fork;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	if ((philo->id - 1) < (philo->id % philo->data->num_philosophers))
		first_fork = philo->id - 1;
	else
		first_fork = philo->id % philo->data->num_philosophers;
	if ((philo->id - 1) >= (philo->id % philo->data->num_philosophers))
		second_fork = philo->id - 1;
	else
		second_fork = philo->id % philo->data->num_philosophers;
	if (philo->data->num_philosophers == 1)
	{
		handle_single_philosopher(philo);
		return (NULL);
	}
	while (!get_simulation_end(philo->data))
		whileroutine(philo, first_fork, second_fork);
	return (NULL);
}

void	create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philosophers)
		pthread_create(&data->philosophers[i].thread, NULL,
			philosopher_routine, &data->philosophers[i]);
}

void	monitor_philosophers(t_data *data)
{
    long long	current_time;
	int			i;

	while (!get_simulation_end(data))
	{
		i = -1;
		while (++i < data->num_philosophers)
		{
			pthread_mutex_lock(&data->philosophers[i].meal_lock);
			current_time = get_time();
			if (current_time - data->philosophers[i].last_meal_time
				> data->time_to_die)
			{
				print_status(data, data->philosophers[i].id, "died");
				set_simulation_end(data, 1);
				pthread_mutex_unlock(&data->philosophers[i].meal_lock);
				return ;
			}
			if (data->max_meals != -1
				&& data->philosophers[i].meals_eaten >= data->max_meals)
				set_simulation_end(data, 1);
			pthread_mutex_unlock(&data->philosophers[i].meal_lock);
		}
		usleep(1000);
	}
}

void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->num_philosophers)
	{
		pthread_mutex_lock(&data->philosophers[i].meal_lock);
		data->philosophers[i].last_meal_time = data->start_time;
		pthread_mutex_unlock(&data->philosophers[i].meal_lock);
		i++;
	}
	create_threads(data);
    monitor_philosophers(data);
    i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
}
