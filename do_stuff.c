/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:13:21 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/23 15:22:24 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_lets_eat(void *arg)
{
	t_get	*get;

	get = (t_get *) arg;
	get->time = ft_get_time();
	while (1)
	{
		get->philo[get->index].each_die = ft_get_time();
		pthread_mutex_lock(&get->philo[get->index].mutex);
		pthread_mutex_lock(&get->clock);
		printf("Hilo de philo num -> %d creado..\n", get->philo[get->index].num);
		printf("%ld\n", get->philo[get->index].each_die - get->time);
		pthread_mutex_unlock(&get->philo[get->index].mutex);
		pthread_mutex_unlock(&get->clock);
		if (get->philo[get->index].each_die - get->time >= get->time_to_eat)
			break ;
	}
	return (NULL);
}

void	ft_create_threads(t_get *get)
{
	int	i;

	i = -1;
	while (++i < get->number_of_philos)
	{
		get->index = i;
		if (0 != pthread_create(&get->philo[i].thread, NULL, ft_lets_eat, get))
			printf("error creating pthread\n");
		pthread_join(get->philo[i].thread, NULL);
	}
}
