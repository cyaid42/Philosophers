/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:52:33 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 22:27:21 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->ptr_data->m_is_dead);
	if (philo->ptr_data->isdead == 1)
	{
		pthread_mutex_unlock(&philo->ptr_data->m_is_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->ptr_data->m_is_dead);
	return (0);
}

int	ft_death(t_philo_acces *data, t_philo *philo, int i)
{
	unsigned long	last_meal_cpy;

	pthread_mutex_lock(&data->m_last_meal);
	last_meal_cpy = philo[i].last_meal;
	pthread_mutex_unlock(&data->m_last_meal);
	if ((get_milliseconds() - data->start
			- last_meal_cpy) >= (unsigned long)data->time_die)
	{
		pthread_mutex_lock(&data->m_is_dead);
		data->isdead = 1;
		pthread_mutex_unlock(&data->m_is_dead);
		print(philo, 5);
		return (1);
	}
	return (0);
}

size_t	get_milliseconds(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "Error gettimeofday\n", 20);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
