/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:07:53 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/21 18:25:24 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_save_args(t_philo *save, char **argv, int argc)
{
	save->number_of_philos = ft_atoi(argv[1]);
	if (save->number_of_philos < 1)
		exit (0);
	save->time_to_die = ft_atoi(argv[2]);
	save->time_to_eat = ft_atoi(argv[3]);
	save->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		save->must_eat = ft_atoi(argv[5]);
	else
		save->must_eat = -1;
}

int main(int argc, char **argv)
{
	t_philo	save;
	struct	timeval current_time;
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Error args!\n");
		exit(0);
	}
	ft_save_args(&save, argv, argc);
	printf("%d\n", save.number_of_philos);
	printf("%d\n", save.time_to_die);
	printf("%d\n", save.time_to_eat);
	printf("%d\n", save.time_to_sleep);
	printf("%d\n", save.must_eat);

	gettimeofday(&current_time, NULL);
	i = current_time.tv_usec + save.time_to_die;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		printf("%d\n", current_time.tv_usec);
		if (current_time.tv_usec  == i)
			break ;
	}
}
