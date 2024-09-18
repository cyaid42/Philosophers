/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:03:10 by cyaid             #+#    #+#             */
/*   Updated: 2024/09/18 03:01:23 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// int putnbr(int  nb)
// {
//     int nbr;

//     nbr = nb;
//     if (nbr == '-2147483648')
//         return ('-2147483648');
//     if (nb > 9)
//     {
//         nb = nb / 10;
//         nb = nb % 10;
//     }
//     if (nb >= 0 && nb <= 9)
//         ft_putchar(nb);
//     if (nb < 0)
//     {
//         nb = -nb;
//         ft_putchar('-');
//     }
// }

void	number_of_arg(char **av, t_data *data)
{
	data->i = 0;
	while (av[data->i + 1])
	{
		data->i++;
		if (data->i > 5)
		{
			printf("Error\nToo many arguments\n");
			exit(1);
		}
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
			printf("|%c|", av[i][j]);
			if (av[i][j] < '0' || av[i][j] > '9')
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
	printf("valeur : %d \n", data->nb[0]);
}

void	nbr_of_philo(t_data *data)
{
	if (data->nb[0] < 1)
	{
		printf("Error\nNot enough philo\n");
		exit (1);
	}
}

void	parsing(char **av, t_data *data)
{
	number_of_arg(av, data);
	only_nbr(av, data);
	nbr_of_philo(data);
}

int	main(int ac, char **av)
{
	static t_data data = {0};
	parsing(av, &data);
}