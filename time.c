/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:41:05 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/21 15:01:46 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
	struct	timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\n", current_time.tv_sec);
	printf("microseconds : %ld\n", current_time.tv_usec);
}
