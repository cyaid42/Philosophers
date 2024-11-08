/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:47:42 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/08 04:56:42 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    print(t_philo *philo, int REASON)
{
    unsigned long elapsed_time;
    
    elapsed_time = get_milliseconds() - philo->ptr_data->start;
    printf("%lu %d ", elapsed_time, philo->index);
    if (REASON == 1)
        printf("has taken a fork\n");
    if (REASON == 2)
        printf("is sleeping\n");
    if (REASON == 3)
        printf("is thinking\n");
    if (REASON == 4)
        printf("is eating\n");
    if (REASON == 5)
        printf("died\n");
}