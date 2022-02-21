/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:18:00 by vifernan          #+#    #+#             */
/*   Updated: 2022/02/21 17:31:07 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*pthread_routine1(void *name)
{
	char	*str = (char *)name;
	printf("%s creado...\n", str);
	return 0;
}

void	*pthread_routine2(void *name)
{
	char	*str = (char *)name;
	printf("%s creado...\n", str);
	return 0;
}

void	*pthread_routine3(void *name)
{
	char	*str = (char *)name;
	printf("%s creado...\n", str);
	return 0;
}

int main()
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	//char	*name1 = "pthread";
	//char	*name2 = "pthread";

	if (0 != pthread_create(&thread1, NULL, pthread_routine1, "thread1"))
	{
		printf("Error\n");
		exit(0);
	}
	if (0 != pthread_create(&thread2, NULL, pthread_routine2, "thread2"))
	{
		printf("Error\n");
		exit(0);
	}
	if (0 != pthread_create(&thread3, NULL, pthread_routine3, "thread3"))
	{
		printf("Error3\n");
		exit(0);
	}
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread2, NULL);
}
