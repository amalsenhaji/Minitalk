/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:08:22 by amsenhaj          #+#    #+#             */
/*   Updated: 2022/02/20 01:09:19 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
	sig -= SIGUSR1;
	if (g_data.client_pid != info->si_pid)
		zero_init();
	g_data.c = g_data.c << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		if (!g_data.c)
		{
			kill(info->si_pid, SIGUSR2);
			info->si_pid = 0;
			return ;
		}
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
