/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:03:10 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 10:04:53 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	free_mutex(t_philo_acces *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	free(philo);
	pthread_mutex_destroy(&data->m_last_meal);
	pthread_mutex_destroy(&data->m_end_meal);
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->m_is_dead);
	pthread_mutex_destroy(&data->m_full);
}

int	ft_check(t_philo_acces *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (ft_death(data, philo, i) == 1)
				return (1);
			if (ft_count_meal(philo) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

int	init_mutex(t_philo_acces *data)
{
	if (pthread_mutex_init(&data->m_print, NULL))
		return (1);
	if (pthread_mutex_init(&data->m_end_meal, NULL))
		return (1);
	if (pthread_mutex_init(&data->m_is_dead, NULL))
		return (1);
	if (pthread_mutex_init(&data->m_last_meal, NULL))
		return (1);
	if (pthread_mutex_init(&data->m_full, NULL))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	static t_philo_acces	data = {0};
	static t_philo			*philo;

	(void)ac;
	init_error(&data);
	parsing(av, &data);
	if (init_philo(&data, &philo))
		return (-1);
	if (init_mutex(&data))
		return (free_mutex(&data, philo), 0);
	if (init_thread(&data, philo))
		return (free_mutex(&data, philo), 0);
}
