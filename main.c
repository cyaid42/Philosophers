/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:03:10 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/08 04:41:47 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}



int	ft_check(t_philo_acces *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (ft_death(data, philo, i))
				return (1);
			if (end_meal(philo) == 1)
				return (printf("REPAS MAX\n"));
			i++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_acces	data  = {0};
	t_philo			*philo = {0};

	init_error(&data);
	parsing(av, &data);
	if (init_philo(&data, &philo))
		return (-1);
	if (init_thread(&data, philo))
		return (-1);
	ft_check(&data, philo);
	// join threads
}
