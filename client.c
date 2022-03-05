/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:32:30 by amsenhaj          #+#    #+#             */
/*   Updated: 2022/02/19 03:53:46 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	send_signals1(av[2], pid);
	return (0);
}
