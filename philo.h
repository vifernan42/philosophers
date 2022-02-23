/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:10:21 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/23 15:04:18 by vifernan         ###   ########.fr       */
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
	time_t			each_die;
	int				num;
	int				fork_right;
	int				fork_left;
	pthread_t		thread;
	pthread_mutex_t	mutex;
} t_philo;

typedef struct	s_get{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				index;
	int				forks;
	time_t			time;
	pthread_mutex_t	clock;
	t_philo			*philo;
} t_get;

void	ft_create_threads(t_get *get);
void	*ft_lets_eat(void *arg);
void	ft_save_args(t_get *get, char **argv, int argc);
time_t	ft_get_time(void);
void	ft_get_philos_info(t_get *get);

#endif
