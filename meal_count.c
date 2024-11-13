/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:26:43 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 22:55:34 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lock_meal(t_philo *philo, int i)
{
	if (i == 1)
	{
		pthread_mutex_lock(&philo->ptr_data->m_end_meal);
		pthread_mutex_lock(&philo->ptr_data->m_count_meal);
	}
	if (i == 2)
	{
		pthread_mutex_unlock(&philo->ptr_data->m_count_meal);
		pthread_mutex_unlock(&philo->ptr_data->m_end_meal);
	}
	if (i == 3)
	{
		pthread_mutex_unlock(&philo->ptr_data->m_count_meal);
		philo->ptr_data->philo_done++;
		pthread_mutex_unlock(&philo->ptr_data->m_end_meal);
	}
}

int	ft_count_meal(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->ptr_data->nb_philo != 1 && philo->ptr_data->opt == 1)
	{
		while (i++ < philo->ptr_data->nb_philo)
		{
			ft_lock_meal(philo, 1);
			if (philo[i].nb_meal >= philo->ptr_data->max_meal)
			{
				ft_lock_meal(philo, 3);
				if (philo->ptr_data->philo_done >= philo->ptr_data->nb_philo)
				{
					pthread_mutex_lock(&philo->ptr_data->m_full);
					philo->meal_print = 1;
					pthread_mutex_unlock(&philo->ptr_data->m_full);
					return (print(philo, 6), 1);
				}
			}
			else
				ft_lock_meal(philo, 2);
		}
	}
	return (0);
}

int	end_meal(t_philo *philo)
{
	if (philo->ptr_data->opt == 1)
	{
		pthread_mutex_lock(&philo->ptr_data->m_end_meal);
		if (philo->ptr_data->philo_done >= philo->ptr_data->nb_philo)
		{
			pthread_mutex_unlock(&philo->ptr_data->m_end_meal);
			return (1);
		}
		pthread_mutex_unlock(&philo->ptr_data->m_end_meal);
	}
	return (0);
}
