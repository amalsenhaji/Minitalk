/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsenhaj <amsenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:10:38 by amsenhaj          #+#    #+#             */
/*   Updated: 2022/02/19 03:27:56 by amsenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	char	c;
	int		client_pid;
}	t_data;

void	handler(int sig, siginfo_t *info, void *ucontext);
void	send_signals1(char *message, int pid);
void	send_signals2(char c, int pid);
void	zero_init(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(char *str);

#endif