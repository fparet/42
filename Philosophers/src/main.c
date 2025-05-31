/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:38:41 by fparet            #+#    #+#             */
/*   Updated: 2025/05/31 15:38:45 by fparet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s num_philos time_to_die time_to_eat\n",
			argv[0]);
		printf("       time_to_sleep [max_meals]\n");
		return (1);
	}
	if (init_data(&data, argc, argv))
	{
		printf("Error: Initialization failed\n");
		return (1);
	}
	start_simulation(&data);
	cleanup(&data);
	return (0);
}
