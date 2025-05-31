/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:38:41 by fparet            #+#    #+#             */
/*   Updated: 2025/05/31 15:38:45 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	meal_lock;
}	t_philosopher;

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				simulation_end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	t_philosopher	*philosophers;
	long long		start_time;
	pthread_mutex_t	simulation_lock;
}	t_data;

//simulation
void		release_forks(t_philosopher *philo);
void		*philosopher_routine(void *arg);
void		create_threads(t_data *data);
void		monitor_philosophers(t_data *data);
void		start_simulation(t_data *data);
void		eat(t_philosopher *philo);
void		handle_single_philosopher(t_philosopher *philo);
void		take_forks(t_philosopher *philo, int first_fork, int second_fork);
void		sleep_and_think(t_philosopher *philo,
				int first_fork, int second_fork);

//init
int			init_mutexes(t_data *data);
int			init_philosophers(t_data *data);
int			init_data(t_data *data, int argc, char **argv);

//cleanup
void		cleanup(t_data *data);

//utils
long long	get_time(void);
void		print_status(t_data *data, int id, char *status);
void		cleanup(t_data *data);
void		smart_sleep(int duration_ms, t_data *data);
int			get_simulation_end(t_data *data);
void		set_simulation_end(t_data *data, int value);

#endif
