/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:13:21 by vifernan          #+#    #+#             */
/*   Updated: 2022/03/01 14:54:32 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(time_t time_x)
{
	time_t	total_time;
	time_t	time_left;

	printf("Ëntra\n");
	total_time = time_x + get_time();
	time_left = get_time();
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
	pthread_mutex_unlock(&data->philo[next].fork_lock);
	pthread_mutex_unlock(&data->philo[order].fork_lock);
	pthread_mutex_lock(&data->eat_lock);
	ft_print_it(data, get_time(), order, 3);
	pthread_mutex_unlock(&data->eat_lock);
	ft_wait(data->time_to_sleep);
	pthread_mutex_lock(&data->eat_lock);
	ft_print_it(data, get_time(), order, 4);
	pthread_mutex_unlock(&data->eat_lock);
}


void	*lets_eat(void *arg)
{
	t_data	*data;
	int		next;
	int		finish;
	int		order;

	data = (t_data *) arg;
	order = data->index++;
	if (order % 2 != 0)
		ft_wait(data->time_to_eat);
	finish = 0;
	while (1)
	{
		printf("full = %d, meals = %d\n", data->philo[order].full, data->meals_to_eat);
		if (data->meals_to_eat != -1 || data->philo[order].full == 1)
			break ;
		else
		{
			if (order == data->number_of_philos - 1)
				next = 0;
			else
				next = order + 1;
			ft_take_fork(data, order, next);
			finish++;
			ft_sleep(data, order, next, finish);
		}
	}
	return (NULL);
}

/*void	*lets_eat(void *arg)
{
	t_philo	*start;
	t_philo	*next;

	start = (t_philo *) arg;
}*/

void	ft_create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, lets_eat, data);
		//pthread_detach(data->philo[i].thread);
	}
	i = -1;
	while (++i < data->number_of_philos)
		pthread_join(data->philo[i].thread, NULL);

}
