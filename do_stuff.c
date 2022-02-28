/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:13:21 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/28 14:53:15 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(time_t time_x)
{
	time_t	total_time;
	time_t	time_left;

	total_time = time_x + ft_get_time();
	time_left = ft_get_time();
	while (total_time > time_left)
	{
		usleep(60);
		time_left = ft_get_time();
	}
}

void	ft_print_it(t_get *get, time_t time_x, int num, int id)
{
	time_t	time_tp;

	time_tp = time_x  - get->time;
	if (id == 1)
		printf("%ld Philo %d has taken a fork\n", time_tp, num);
	else if (id == 2)
		printf("%ld Philo %d is eating\n", time_tp, num);
	else if (id == 3)
		printf("%ld Philo %d is sleeping\n", time_tp, num);
	else if (id == 4)
		printf("%ld Philo %d is thinking\n", time_tp, num);

}

void	ft_take_fork(t_get *get, int order,int next)
{
	pthread_mutex_lock(&get->philo[order].mutex);
	pthread_mutex_lock(&get->clock);
	ft_print_it(get, ft_get_time(), order, 1);
	pthread_mutex_unlock(&get->clock);
	pthread_mutex_lock(&get->philo[next].mutex);
	get->philo[order].each_die = ft_get_time();
	pthread_mutex_lock(&get->clock);
	ft_print_it(get, get->philo[order].each_die, order, 1);
	ft_print_it(get, get->philo[order].each_die, order, 2);
	pthread_mutex_unlock(&get->clock);
	ft_wait(get->time_to_eat);
}

void	ft_sleep(t_get *get, int order, int next, int finish)
{
	if (get->must_eat > 0 && finish == get->must_eat)
		get->philo[order].full = 1;
	pthread_mutex_unlock(&get->philo[next].mutex);
	pthread_mutex_unlock(&get->philo[order].mutex);
	pthread_mutex_lock(&get->clock);
	ft_print_it(get, ft_get_time(), order, 3);
	pthread_mutex_unlock(&get->clock);
	ft_wait(get->time_to_sleep);
	pthread_mutex_lock(&get->clock);
	ft_print_it(get, ft_get_time(), order, 4);
	pthread_mutex_unlock(&get->clock);
}


void	*ft_lets_eat(void *arg)
{
	t_get	*get;
	int		next;
	int		finish;
	int		order;

	get = (t_get *) arg;
	finish = 0;
	order = get->index++;
	if (order % 2 != 1)
		ft_wait(get->time_to_eat);
	while (1)
	{
		if (get->must_eat != -1 || get->philo[order].full == 1)
			break ;
		else
		{
			//printf("n_o_f-> %d | order-> %d\n", get->number_of_philos, order);
			if (order == get->number_of_philos - 1)
				next = 0;
			else
				next = order + 1;
			ft_take_fork(get, order, next);
			finish++;
			ft_sleep(get, order, next, finish);
		}
	}
	return (NULL);
}

void	ft_create_threads(t_get *get)
{
	int	i;

	i = 0;
	while (i < get->number_of_philos)
	{
		printf("Cuenta<%d>\n", i);
		pthread_create(&get->philo[i].thread, NULL, ft_lets_eat, get);
		pthread_detach(get->philo[i].thread);
		i++;
	}
}
