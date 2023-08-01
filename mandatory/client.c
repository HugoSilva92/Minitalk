/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:27:21 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/14 13:40:27 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_sender(int pid, char c)
{
	int	bits;

	bits = -1;
	while (++bits < 8)
	{
		if ((c & (1 << bits)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			bit_sender(pid, av[2][i++]);
		bit_sender(pid, '\n');
	}
	else
	{
		ft_printf("Error!");
		exit(EXIT_FAILURE);
	}
}
