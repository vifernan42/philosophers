/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:41:05 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/21 18:27:47 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
	struct	timeval current_time;
	int		i;

	//printf("seconds : %ld\n", current_time.tv_sec);
	//printf("microseconds : %d\n", current_time.tv_usec);
	
	while (1)
	{
		gettimeofday(&current_time, NULL);
		i = current_time.tv_usec;
		printf("%d\n", i);
	}
}
