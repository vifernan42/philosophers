/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:07:53 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/22 18:04:47 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_save_args(t_get *get, char **argv, int argc)
{
	get->number_of_philos = ft_atoi(argv[1]);
	if (get->number_of_philos < 1)
		exit (0);
	get->time_to_die = ft_atoi(argv[2]);
	get->time_to_eat = ft_atoi(argv[3]);
	get->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		get->must_eat = ft_atoi(argv[5]);
	else
		get->must_eat = -1;
}

time_t	ft_get_time(void)
{
	struct	timeval current_time;
	
	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_get_philos_info(t_get *get)
{
	int	i;
	int	j;

	get->philos = malloc(sizeof(t_philos) * get->number_of_philos);
	i = -1;
	j = 1;
	while (++i < get->number_of_philos)
		get->philos[i].each_time = ft_get_time();
}

int main(int argc, char **argv)
{
	t_get get;
//	time_t	time;
//	time_t	st_time;

	if (argc != 5 && argc != 6)
	{
		printf("Error args!\n");
		exit(0);
	}
	ft_save_args(&get, argv, argc);
	
	/*st_time = ft_get_time();
	while (1)
	{
		time = ft_get_time();
		printf("%ld\n", time - st_time);
		if (time - st_time > s_get.time_to_die)
			break ;
	}*/
	exit (0);
}
