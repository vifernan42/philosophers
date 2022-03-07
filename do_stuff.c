/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:13:21 by vifernan          #+#    #+#             */
/*   Updated: 2022/03/07 14:42:14 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(time_t time_x)
{
	time_t	total_time;
	time_t	time_left;

	total_time = time_x + get_time();
	//printf("time_x = %ld\n", time_x);
	//printf("total_time %ld\n", total_time);
	time_left = get_time();
	//printf("time_left %ld\n", total_time);
	while (total_time > time_left)
	{
		usleep(60);
		time_left = get_time();
	}
}

void	ft_print_it(t_data *data, time_t time_x, int num, int id)
{
	time_t	time_tp;

	time_tp = time_x  - data->time;
	if (id == 1)
		printf("%ld Philo %d has taken a fork\n", time_tp, num);
	else if (id == 2)
		printf("%ld Philo %d is eating\n", time_tp, num);
	else if (id == 3)
		printf("%ld Philo %d is sleeping\n", time_tp, num);
	else if (id == 4)
		printf("%ld Philo %d is thinking\n", time_tp, num);

}
/*
void	ft_take_fork(t_data *data, int order,int next)
{
	pthread_mutex_lock(&data->philo[order].fork_lock);
	pthread_mutex_lock(&data->eat_lock);
	ft_print_it(data, get_time(), order, 1);
	pthread_mutex_unlock(&data->eat_lock);
	pthread_mutex_lock(&data->philo[next].fork_lock);
	data->philo[order].last_meal = get_time();
	pthread_mutex_lock(&data->eat_lock);
	ft_print_it(data, data->philo[order].last_meal, order, 1);
	ft_print_it(data, data->philo[order].last_meal, order, 2);
	pthread_mutex_unlock(&data->eat_lock);
	ft_wait(data->time_to_eat);
}

void	ft_sleep(t_data *data, int order, int next, int finish)
{
	if (data->meals_to_eat > 0 && finish == data->meals_to_eat)
		data->philo[order].full = 1;
	printf("++++++++\n");
	pthread_mutex_unlock(&data->philo[next].fork_lock);
	pthread_mutex_unlock(&data->philo[order].fork_lock);
	pthread_mutex_lock(&data->eat_lock);
	ft_print_it(data, get_time(), order, 3);
	pthread_mutex_unlock(&data->eat_lock);
	ft_wait(data->time_to_sleep);
	pthread_mutex_lock(&data->eat_lock);
	ft_print_it(data, get_time(), order, 4);
	pthread_mutex_unlock(&data->eat_lock);
}*/

void	*lets_eat(void *arg)
{
	t_data	*data;
	int		next;
	int		finish;
	int		order;

	data = (t_data *) arg;
	order = data->index++;
	//printf("------->%d\n", order);
	if (order % 2 != 1)
		ft_wait((time_t)data->time_to_eat);
	finish = 0;
	while (1)
	{
		//printf("full = %d, meals = %d\n", data->philo[order].full, data->meals_to_eat);
		if (data->meals_to_eat == -1 || data->philo[order].full != 0)
		{
			if (order == data->number_of_philos - 1)
				next = 0;
			else
				next = order + 1;

			pthread_mutex_lock(&data->philo[order].fork_lock);
			pthread_mutex_lock(&data->eat_lock);
			ft_print_it(data, get_time(), order, 1);
			pthread_mutex_unlock(&data->eat_lock);
			pthread_mutex_lock(&data->philo[next].fork_lock);
			data->philo[order].last_meal = get_time();
			pthread_mutex_lock(&data->eat_lock);
			ft_print_it(data, data->philo[order].last_meal, order, 1);
			ft_print_it(data, data->philo[order].last_meal, order, 2);
			pthread_mutex_unlock(&data->eat_lock);
			//printf("tt_eat= %d\n", data->time_to_eat);
			ft_wait((time_t)data->time_to_eat);
			printf("++++++++\n");
			finish++;
			if (data->meals_to_eat > 0 && finish == data->meals_to_eat)
				data->philo[order].full = 1;
			pthread_mutex_unlock(&data->philo[next].fork_lock);
			pthread_mutex_unlock(&data->philo[order].fork_lock);
			pthread_mutex_lock(&data->eat_lock);
			ft_print_it(data, get_time(), order, 3);
			pthread_mutex_unlock(&data->eat_lock);
			ft_wait((time_t)data->time_to_sleep);
			pthread_mutex_lock(&data->eat_lock);
			ft_print_it(data, get_time(), order, 4);
			pthread_mutex_unlock(&data->eat_lock);
			/*ft_take_fork(data, order, next);
			finish++;
			printf("++++++++\n");
			ft_sleep(data, order, next, finish);*/
		}
		else
			return (NULL);
	}
	return (NULL);
}

void	ft_create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, lets_eat, data);
		pthread_detach(data->philo[i].thread);
	}
}