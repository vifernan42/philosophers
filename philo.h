/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <vifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:10:21 by vifernan          #+#    #+#             */
/*   Updated: 2022/03/01 14:40:36 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <pthread.h>
#include "./libft/libft.h"

typedef struct	s_philo{
	time_t			last_meal;
	int				id;
	int				full;
	pthread_t		thread;
	pthread_mutex_t	fork_lock;
	pthread_mutex_t	last_meal_lock;
} t_philo;

typedef struct	s_data{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	int				index;
	time_t			time;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	die_lock;
	t_philo			*philo;
} t_data;

void	ft_create_threads(t_data *data);
void	*lets_eat(void *arg);
void	ft_save_args(t_data *data, char **argv, int argc);
time_t	get_time(void);
void	init_philos(t_data *data);

#endif
