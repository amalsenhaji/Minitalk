/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 05:46:26 by amsenhaj          #+#    #+#             */
/*   Updated: 2022/02/20 01:31:06 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signals2(char c, int pid)
{
	int	bitshift;

	bitshift = 0;
	while (bitshift < 8)
	{
		if (c & (0x80 >> bitshift))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(500);
		bitshift++;
	}
}

void	handler_signal(int signum)
{
	(void)signum;
	ft_putstr("Vu🙂");
	exit(0);
}

void	send_signals1(char *message, int pid)
{
	int	i;

	i = -1;
	while (message[++i])
		send_signals2(message[i], pid);
	send_signals2(message[i], pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("Usage ----> ./client [server-pid] [message]\n");
		exit(0);
	}
	if (!av[2])
	{
		ft_putstr("INVALID MESSAGE\n");
		exit(0);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR2, handler_signal);
	send_signals1(av[2], pid);
	return (0);
}
