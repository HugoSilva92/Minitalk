/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:47:29 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/15 22:57:47 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	received(int sig)
{
	static int	rec;

	if (!rec)
	{
		if (sig == SIGUSR2)
		{
			ft_printf("Message received!\n");
			rec = 1;
		}
	}
}

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
		{
			signal(SIGUSR1, &received);
			signal(SIGUSR2, &received);
			bit_sender(pid, av[2][i++]);
		}
		bit_sender(pid, '\n');
	}
	else
	{
		ft_printf("Error!");
		exit(EXIT_FAILURE);
	}
}
