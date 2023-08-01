/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:27:23 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/14 13:39:27 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
