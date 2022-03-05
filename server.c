/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:32:22 by amsenhaj          #+#    #+#             */
/*   Updated: 2022/02/20 03:52:12 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	zero_init(void)
{
	g_data.i = 0;
	g_data.c = 0;
	g_data.client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	sig = sig - SIGUSR1;
	if (g_data.client_pid != info->si_pid)
		zero_init();
	g_data.c = g_data.c << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		write(1, &g_data.c, 1);
		zero_init();
	}
	g_data.client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	senhaji;

	zero_init();
	ft_putstr("pid :    ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	senhaji.sa_sigaction = &handler;
	senhaji.sa_flags = SA_SIGINFO;
	sigemptyset(&senhaji.sa_mask);
	sigaddset(&senhaji.sa_mask, SIGUSR1);
	sigaddset(&senhaji.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &senhaji, NULL);
	sigaction(SIGUSR2, &senhaji, NULL);
	while (1)
		sleep(1);
}
