/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:12:33 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 10:06:14 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	better_sleep(size_t ms)
{
	size_t	start;

	start = get_milliseconds();
	while (((get_milliseconds() - start)) < ms)
	{
		usleep(100);
	}
}

void	go_think(t_philo *philo, int i)
{
	print(philo, 3);
	better_sleep(i);
}

void	go_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	print(philo, 1);
	print(philo, 1);
	print(philo, 4);
	pthread_mutex_lock(&philo->ptr_data->m_last_meal);
	philo->last_meal = get_milliseconds() - philo->ptr_data->start;
	pthread_mutex_unlock(&philo->ptr_data->m_last_meal);
	better_sleep(philo->ptr_data->time_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	go_sleep(t_philo *philo)
{
	print(philo, 2);
	better_sleep(philo->ptr_data->time_sleep);
}
