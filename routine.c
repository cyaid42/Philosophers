/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:11:36 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 09:52:19 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->ptr_data->nb_philo == 1)
		usleep(philo->ptr_data->time_die + 10);
	while (!(is_dead(philo)) && !(end_meal(philo))
		&& philo->ptr_data->nb_philo != 1)
	{
		if (!(is_dead(philo)) && !(end_meal(philo)))
			go_eat(philo);
		if (!(is_dead(philo)) && !(end_meal(philo)))
			go_sleep(philo);
		if (!(is_dead(philo)) && !(end_meal(philo)))
			go_think(philo, 1);
	}
	return (NULL);
}
