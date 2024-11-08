/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:12:33 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/08 04:49:03 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    better_sleep(suseconds_t ms, t_philo *philo)
{
    size_t  start;

    start = get_milliseconds();
    while (get_milliseconds() - start < ms)
    {
        usleep(1000);
    }
}

void    go_think(t_philo *philo)
{
    usleep(400);
    print(philo, 3);
    if (philo->ptr_data->time_eat > philo->ptr_data->time_sleep && philo->ptr_data->nb_philo % 2 == 1)
        better_sleep(philo->ptr_data->time_eat - philo->ptr_data->time_sleep + 10, philo);
}

void    go_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print(philo, 1);
    pthread_mutex_lock(philo->left_fork);
    print(philo, 1);
    print(philo, 4);
    better_sleep(philo->ptr_data->time_eat, philo);
    philo->nb_meal++;
    if (philo->nb_meal >= philo->ptr_data->max_meal)
        philo->ptr_data->philo_done++;
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    philo->last_meal = get_milliseconds() - philo->ptr_data->start;
    // printf("%d", philo->nb_meal);
}

void    go_sleep(t_philo *philo)
{
    print(philo, 2);
    better_sleep(philo->ptr_data->time_sleep, philo);
}