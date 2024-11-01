/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 04:04:25 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/01 23:16:09 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **av, t_data *data, t_data *info)
{
	number_of_arg(av, data);
	
	only_nbr(av, data);
	valid_number(data);
	// printf("%d\n", data->relevent_info.max_meal);
}

void	number_of_arg(char **av, t_data *data)
{
	data->i = 0;
	while (av[data->i + 1])
		data->i++;
	if (data->i < 4 || data->i > 5)
	{
		printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
	if (data->i == 5)
		data->opt = 1;
	else
		data->opt = 0;
}

void	only_nbr(char **av, t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] != '-' && (av[i][j] < '0' || av[i][j] > '9'))
			{
				printf("Error\nPas un nombre\n");
				exit(1);
			}
			j++;
		}
		data->nb[k] = atoi(av[i]);
		i++;
		k++;
		j = 0;
	}
}

int	problem(int i, t_data *data)
{
	printf("Error\n%s\n", data->error_code.code[i]);
	exit (1);
}

int	valid_number(t_data *data)
{
	int	i;

	i = 0;
	while (data->nb[i] != data->nb[5])
	{
			printf("%d\n", i);
		if (data->nb[i] < 1)
		{
			problem(i, data);
		}
		i++;
	}
	return (1);
}