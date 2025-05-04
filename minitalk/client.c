/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:17:59 by stliu             #+#    #+#             */
/*   Updated: 2025/05/04 13:31:53 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	shift_bits(int server_pid, char *s)
{
	int	bit;

	while (*s)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((*s >> (7 - bit)) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		s++;
	}
	bit = 0;
	while (bit < 8)
	{
		kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*s;

	if (argc != 3)
	{
		ft_printf("Error occured: Invalid number of arguments\n");
		exit(1);
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
