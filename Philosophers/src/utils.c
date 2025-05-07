#include "philosophers.h"


long long get_time(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void print_status(t_data *data, int id, char *status)
{
	pthread_mutex_lock(&data->print_lock);
	if (!data->simulation_end)
		printf("%lld %d %s\n", get_time() - data->start_time, id, status);
	pthread_mutex_unlock(&data->print_lock);
}

void cleanup(t_data *data)
{
	int i;

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

	start = get_time();
	while (!data->simulation_end && (get_time() - start < duration_ms))
		usleep(500);
}

