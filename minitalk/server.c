/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:26:40 by stliu             #+#    #+#             */
/*   Updated: 2025/05/05 16:23:22 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"
#include "libft/libft.h"

void	*ft_realloc(void *ptr, int size, int new_size)
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

static void	handle_string(char **buffer, int *buffer_len, char c)
{
	char	*temp;

	if (c == '\0')
	{
		if (*buffer != NULL)
		{
			ft_printf("%s", *buffer);
			free(*buffer);
			*buffer = NULL;
			*buffer_len = 0;
		}
		return ;
	}
	temp = ft_realloc(*buffer, *buffer_len, *buffer_len + 2);
	if (temp == NULL)
	{
		if (*buffer)
			free(*buffer);
		ft_printf("Memory alloc failed.\n");
		exit(1);
	}
	*buffer = temp;
	(*buffer)[(*buffer_len)++] = c;
	(*buffer)[*buffer_len] = '\0';
}

void	handle_signal(int signal)
{
	static char	*buffer;
	static char	c;
	static int	bit_pos;
	static int	buffer_len;

	if (bit_pos == 0)
		c = 0;
	if (signal == SIGUSR1)
		c |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8)
	{
		handle_string(&buffer, &buffer_len, c);
		bit_pos = 0;
	}
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
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
