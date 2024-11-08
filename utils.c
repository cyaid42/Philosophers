/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:52:33 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/08 04:41:56 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	if (philo->ptr_data->isdead == 1)
	{
		return (1);
	}
	return (0);			
}

int	end_meal(t_philo *philo)
{
	if (philo->ptr_data->philo_done >= philo->ptr_data->nb_philo)
	{
        printf(" %d last Meal\n", philo->index);
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

int	ft_death(t_philo_acces *data, t_philo *philo, int i)
{
	unsigned long	last_meal_cpy;

	last_meal_cpy = philo[i].last_meal;
	if ((get_milliseconds() - data->start - last_meal_cpy)
		 >= (unsigned long)data->time_die)
	{
		data->isdead = 1;
		print(philo, 5);
		return (1);
	}
	return (0);
}