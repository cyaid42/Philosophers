/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:57:47 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/13 21:59:43 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

// # include "Libft/libft.h"
# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_error_code
{
	char					*code[5];
}							t_error_code;

typedef struct s_philo		t_philo;

typedef struct s_philo_acces
{
	int						i;
	int						opt;
	int						nb[5];
	int						nb_philo;
	int						time_die;
	int						time_sleep;
	int						time_eat;
	int						max_meal;
	unsigned long			start;
	int						check;
	bool					isdead;
	int						philo_done;
	bool					end;
	t_error_code			error_code;
	pthread_mutex_t			*forks;
	pthread_mutex_t			m_print;
	pthread_mutex_t			m_is_dead;
	pthread_mutex_t			m_end_meal;
	pthread_mutex_t			m_last_meal;
	pthread_mutex_t			m_count_meal;
	pthread_mutex_t			m_full;
}							t_philo_acces;

typedef struct s_philo
{
	pthread_t				pid;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	int						index;
	int						last_meal;
	int						nb_meal;
	int						i;
	int						meal_print;
	int						death;
	struct s_philo_acces	*ptr_data;

}							t_philo;

// PARSING//

void						parsing(char **av, t_philo_acces *data);
void						only_nbr(char **av, t_philo_acces *data);
void						number_of_arg(char **av, t_philo_acces *data);
void						philo(t_philo_acces *data);
int							valid_number(t_philo_acces *data);
int							problem(int i, t_philo_acces *data);

// INIT//

size_t						get_milliseconds(void);
void						init_info(t_philo_acces *data);
void						init_error(t_philo_acces *data);
int							init_philo(t_philo_acces *data, t_philo **philo);
int							init_thread(t_philo_acces *data, t_philo *philo);

// UTILS//

int							end_meal(t_philo *philo);
int							is_dead(t_philo *philo);
int							ft_death(t_philo_acces *data, t_philo *philo,
								int i);

// ROUTINE//

void						*routine(void *arg);
int							ft_check(t_philo_acces *data, t_philo *philo);
int							ft_count_meal(t_philo *philo);

// ACTION//

void						go_think(t_philo *philo, int i);
void						go_eat(t_philo *philo);
void						go_sleep(t_philo *philo);

// PRINT//

void						print(t_philo *philo, int REASON);

#endif