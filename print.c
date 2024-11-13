/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:47:42 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 09:51:07 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, int REASON)
{
	unsigned long	elapsed_time;

	pthread_mutex_lock(&philo->ptr_data->m_print);
	elapsed_time = get_milliseconds() - philo->ptr_data->start;
	if (philo->ptr_data->isdead == 0 && philo->meal_print == 0)
	{
		printf("%lu %d ", elapsed_time, philo->index);
		if (REASON == 1)
			printf("has taken a fork\n");
		else if (REASON == 2)
			printf("is sleeping\n");
		else if (REASON == 3)
			printf("is thinking\n");
		else if (REASON == 4)
			printf("is eating\n");
	}
	if (REASON == 5)
		printf("%lu %d died\n", elapsed_time, philo->index);
	if (REASON == 6)
		printf("%lu %d is eating\n", elapsed_time, philo->index);
	pthread_mutex_unlock(&philo->ptr_data->m_print);
}
