/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:47:08 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/14 14:14:35 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig, siginfo_t *info, void *signal)
{
	static int	bit;
	static int	i;
	int			pid;

	pid = info->si_pid;
	(void)signal;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(pid, SIGUSR2);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
}
