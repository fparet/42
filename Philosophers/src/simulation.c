#include "philosophers.h"
/*
void take_forks(t_philosopher *philo)
{
    t_data *data = philo->data;

    if (philo->id % 2 == 0)
        pthread_mutex_lock(&data->forks[philo->id % data->num_philosophers]);
    pthread_mutex_lock(&data->forks[philo->id - 1]);
    if (philo->id % 2 == 0)
        pthread_mutex_lock(&data->forks[philo->id - 1]);
    pthread_mutex_lock(&data->forks[philo->id % data->num_philosophers]);
    print_status(data, philo->id, "has taken both forks");
}

void release_forks(t_philosopher *philo)
{
    t_data *data = philo->data;

    pthread_mutex_unlock(&data->forks[philo->id - 1]);
    pthread_mutex_unlock(&data->forks[philo->id % data->num_philosophers]);
    print_status(data, philo->id, "has released forks");
}


void *philosopher_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;

	while (!philo->data->simulation_end) {
		print_status(philo->data, philo->id, "is thinking");
		take_forks(philo);
		print_status(philo->data, philo->id, "is eating");
		philo->last_meal_time = get_time();
		usleep(philo->data->time_to_eat * 1000);
		philo->meals_eaten++;
		release_forks(philo);
		print_status(philo->data, philo->id, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}


void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    while (!philo->data->simulation_end) {
        // Philosophe pense
        print_status(philo->data, philo->id, "is thinking");
        // Philosophe prend les fourchettes
        pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
        print_status(philo->data, philo->id, "has taken a fork");
        pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->num_philosophers]);
        print_status(philo->data, philo->id, "has taken a fork");
        // Philosophe mange
		pthread_mutex_lock(&philo->meal_lock);
        print_status(philo->data, philo->id, "is eating");
        philo->last_meal_time = get_time();
        usleep(philo->data->time_to_eat * 1000);
        philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_lock);
        // Philosophe repose les fourchettes
        pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
        pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->num_philosophers]);
        // Philosophe dort
        print_status(philo->data, philo->id, "is sleeping");
        usleep(philo->data->time_to_sleep * 1000);
    }
    return (NULL);
}
*/

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		usleep(1000); // léger décalage pour éviter deadlock

	while (!philo->data->simulation_end)        //APROTEC
	{
		print_status(philo->data, philo->id, "is thinking");

		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		print_status(philo->data, philo->id, "has taken a fork");

		pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->num_philosophers]);
		print_status(philo->data, philo->id, "has taken a fork");

		pthread_mutex_lock(&philo->meal_lock);
		print_status(philo->data, philo->id, "is eating");
		philo->last_meal_time = get_time();
		pthread_mutex_unlock(&philo->meal_lock);

		smart_sleep(philo->data->time_to_eat, philo->data);
		pthread_mutex_lock(&philo->meal_lock);
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->meal_lock);


		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->num_philosophers]);

		print_status(philo->data, philo->id, "is sleeping");
		smart_sleep(philo->data->time_to_sleep, philo->data);
	}
	return (NULL);
}


void create_threads(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philosophers)
		pthread_create(&data->philosophers[i].thread, NULL, philosopher_routine, &data->philosophers[i]);
}

void monitor_philosophers(t_data *data)
{
	int i;
    long long current_time;

    while (!get_simulation_end(data))
	{
        i = -1;
        while (++i < data->num_philosophers)
		{
			pthread_mutex_lock(&data->philosophers[i].meal_lock);
            current_time = get_time();
            if (current_time - data->philosophers[i].last_meal_time > data->time_to_die) 
			{
                print_status(data, data->philosophers[i].id, "died");
                set_simulation_end(data, 1);
				pthread_mutex_unlock(&data->philosophers[i].meal_lock);
                break;
            }
			pthread_mutex_unlock(&data->philosophers[i].meal_lock);
            if (data->max_meals != -1 &&
                data->philosophers[i].meals_eaten >= data->max_meals)   //APROTEC
                set_simulation_end(data, 1);
        }
        usleep(1000);
    }
}

void start_simulation(t_data *data)
{
	data->start_time = get_time();
	//for (int i = 0; i < data->num_philosophers; i++)
	//	data->philosophers[i].last_meal_time = data->start_time;
    for (int i = 0; i < data->num_philosophers; i++)
    {
	    pthread_mutex_lock(&data->philosophers[i].meal_lock);
	    data->philosophers[i].last_meal_time = data->start_time;
	    pthread_mutex_unlock(&data->philosophers[i].meal_lock);
    }
    create_threads(data);
    monitor_philosophers(data);
    for (int i = 0; i < data->num_philosophers; i++)
        pthread_join(data->philosophers[i].thread, NULL);
}
