/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:03:10 by cyaid             #+#    #+#             */
/*   Updated: 2024/11/01 22:44:20 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	init_error(t_data *data)
{
	data->error_code.code[0] = "Not enough philosophers";
	data->error_code.code[1] = "Time to die invalid";
	data->error_code.code[2] = "Time to eat invalid";
	data->error_code.code[3] = "Time to sleep invalid";
	data->error_code.code[4] = "Number of time each philosopher must eat invalid";
}

int	main(int ac, char **av)
{
	static t_data	data = {0};
	static t_data	info = {0};
	init_error(&data);
	parsing(av, &data, &info);
	// philo()
}
