/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:26:40 by stliu             #+#    #+#             */
/*   Updated: 2025/06/06 17:05:26 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minitalk.h"

static char	*g_global_buf = NULL;

static void	*ft_realloc(void *ptr, int size, int new_size)
{
	void	*realloc_ptr;

	if (new_size <= 0)
		return (free(ptr), NULL);
	if (ptr == NULL)
		return (malloc(new_size));
	realloc_ptr = malloc(new_size);
	if (realloc_ptr == NULL)
		return (free(ptr), NULL);
	if (size > 0)
		ft_memcpy(realloc_ptr, ptr, size);
	free(ptr);
	return (realloc_ptr);
}

static void	handle_string(pid_t client_pid, int *buffer_len, char c)
{
	char	*temp;

	if (c == '\0')
	{
		if (g_global_buf != NULL)
		{
			ft_printf("%s", g_global_buf);
			free(g_global_buf);
			g_global_buf = NULL;
			*buffer_len = 0;
		}
		return ;
	}
	temp = ft_realloc(g_global_buf, *buffer_len, *buffer_len + 2);
	if (temp == NULL)
	{
		if (g_global_buf != NULL)
			free(g_global_buf);
		ft_printf("Memory alloc failed.\n");
		kill(client_pid, SIGUSR2);
		exit(1);
	}
	g_global_buf = temp;
	g_global_buf[(*buffer_len)++] = c;
	g_global_buf[*buffer_len] = '\0';
}

static void	reset_state(int *len, char **g_global_buf, char *c, int *bit_pos)
{
	if (*g_global_buf != NULL)
	{
		free(*g_global_buf);
		*g_global_buf = NULL;
	}
	*len = 0;
	*c = 0;
	*bit_pos = 0;
	return ;
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		bit_pos;
	static int		buffer_len;
	static pid_t	client_pid;

	(void)context;
	if (bit_pos == 0)
		c = 0;
	if (client_pid != 0 && info->si_pid != client_pid)
		reset_state(&buffer_len, &g_global_buf, &c, &bit_pos);
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8)
	{
		handle_string(client_pid, &buffer_len, c);
		bit_pos = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	if (server_pid == -1)
	{
		ft_printf("Server PID not found.\n");
		exit(1);
	}
	ft_printf("Server PID: %d\n", server_pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
