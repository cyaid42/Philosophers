/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:11:36 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/08 04:46:45 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->index % 2)
		go_think(philo);
	while (!(is_dead(philo)) && !(end_meal(philo)))
	{
		if (!(is_dead(philo)) && !(end_meal(philo)))
			go_eat(philo);
		if (!(is_dead(philo)) && !(end_meal(philo)))
			go_sleep(philo);
		if (!(is_dead(philo)) && !(end_meal(philo)))
			go_think(philo);
		usleep(250);
		// printf("\nROUTINE [%d]\n\n", philo->i);
		// philo->i++;
	}
	return (NULL);
}