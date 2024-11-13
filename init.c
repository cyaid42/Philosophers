/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:11:24 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 10:12:25 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(t_philo_acces *data)
{
	int	i;

	data->nb_philo = data->nb[0];
	data->time_die = data->nb[1];
	data->time_eat = data->nb[2];
	data->time_sleep = data->nb[3];
	i = 0;
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return ;
	while (i < data->nb_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	if (data->opt == 1)
		data->max_meal = data->nb[4];
}

void	init_error(t_philo_acces *data)
{
	data->error_code.code[0] = "Not enough philosophers";
	data->error_code.code[1] = "Time to die invalid";
	data->error_code.code[2] = "Time to eat invalid";
	data->error_code.code[3] = "Time to sleep invalid";
	data->error_code.code[4] = "Invalid optionnal info";
}

int	init_philo(t_philo_acces *data, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * (data->nb_philo));
	if (!(*philo))
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		if (i % 2)
		{
			(*philo)[i].left_fork = &data->forks[i];
			(*philo)[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		}
		else
		{
			(*philo)[i].left_fork = &data->forks[(i + 1) % data->nb_philo];
			(*philo)[i].right_fork = &data->forks[i];
		}
		(*philo)[i].index = i + 1;
		(*philo)[i].last_meal = 0;
		(*philo)[i].nb_meal = 0;
		(*philo)[i].ptr_data = data;
		i++;
	}
	return (0);
}

int	ft_part2(t_philo_acces *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].pid, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_thread(t_philo_acces *data, t_philo *philo)
{
	int	i;

	i = 1;
	data->start = get_milliseconds();
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].pid, NULL, &routine, &philo[i]))
			return (1);
		i += 2;
	}
	usleep(100);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].pid, NULL, &routine, &philo[i]))
			return (1);
		i += 2;
	}
	ft_check(data, philo);
	if (ft_part2(data, philo))
		return (1);
	return (0);
}
