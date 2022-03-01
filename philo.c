/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:07:53 by vifernan          #+#    #+#             */
/*   Updated: 2022/03/01 14:47:36 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_save_args(t_data *data, char **argv, int argc)
{
	data->number_of_philos = ft_atoi(argv[1]);
	if (data->number_of_philos < 1)
		exit (0);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_to_eat = ft_atoi(argv[5]);
	else
		data->meals_to_eat = -1;
}

time_t	get_time(void)
{
	struct	timeval current_time;
	
	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	init_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->number_of_philos);
	i = -1;
	while (++i < data->number_of_philos)
	{
		data->philo[i].last_meal = get_time();
		data->philo[i].id = i + 1;
		data->philo[i].full = 0;
		pthread_mutex_init(&data->philo[i].fork_lock, NULL);
	}
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 5 && argc != 6)
	{
		printf("Error args!\n");
		exit(0);
	}
	ft_save_args(&data, argv, argc);
	data.time = get_time();
	data.index = 0;
	pthread_mutex_init(&data.die_lock, NULL);
	pthread_mutex_init(&data.eat_lock, NULL);
	init_philos(&data);
	ft_create_threads(&data);
	exit (0);
}
