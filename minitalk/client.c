/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:17:59 by stliu             #+#    #+#             */
/*   Updated: 2025/06/06 13:09:00 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk.h"

volatile sig_atomic_t	g_received_signal = 0;

static void	ackknowledge_sig(int sig)
{
	(void)sig;
	g_received_signal = 1;
}

static void	send_signal(int server_pid, int val)
{
	g_received_signal = 0;
	if (val)
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			ft_printf("Error: Failed to send Signal");
			exit(1);
		}
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
		{
			ft_printf("Error: Failed to send Signal");
			exit(1);
		}
	}
	while (!g_received_signal)
		usleep(100);
}

static void	shift_bits(int server_pid, char *s)
{
	int	bit;

	signal(SIGUSR1, ackknowledge_sig);
	while (*s)
	{
		bit = 0;
		while (bit < 8)
		{
			send_signal(server_pid, (*s >> (7 - bit)) & 1);
			bit++;
		}
		s++;
	}
	bit = 0;
	while (bit < 8)
	{
		send_signal(server_pid, 0);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*s;
	char	*pid_str;

	if (argc != 3)
	{
		ft_printf("Error occured: Invalid number of arguments\n");
		exit(1);
	}
	pid_str = argv[1];
	while (*pid_str)
	{
		if (!ft_isdigit(*pid_str))
			return (ft_printf("Error: Invalid server PID\n"), exit(1), 1);
		pid_str++;
	}
	server = ft_atoi(argv[1]);
	s = argv[2];
	if (server <= 0)
	{
		ft_printf("Error: Invalid server PID\n");
		exit(1);
	}
	shift_bits(server, s);
	return (0);
}
