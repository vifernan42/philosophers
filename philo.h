/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:10:21 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/21 12:33:40 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./libft/libft.h"

typedef struct	save{
	int		number_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
} t_save;

#endif
