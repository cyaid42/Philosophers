/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:57:47 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/01 22:42:24 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

// # include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
#include <stdbool.h>

typedef struct relevent_info
{
    int nb_philo;
    int time_die;
    int time_sleep;
    int time_eat;
    bool max_meal;
    
}   r_info;

typedef struct error_code
{
    char *code[4];
    
    
}   r_code;


typedef struct philo
{
    int i;
    int opt;
    int nb[4];
    int nb_philo;
    r_info relevent_info;
    r_code  error_code;
}   t_data;


void	only_nbr(char **av, t_data *data);
void	number_of_arg(char **av, t_data *data);
void	parsing(char **av, t_data *data, t_data *info);
void    philo(t_data *data);
int	valid_number(t_data *data);
int	problem(int i, t_data *data);


#endif