/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:47:07 by stliu             #+#    #+#             */
/*   Updated: 2025/03/31 20:16:18 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			buffer[i] = '\\';
		ft_putstr(buffer);
		i++;
	}
}

static char	*read_files(int fd)
{
	int			bytes_read;
	char		*buffer;
	static int	count;

	count = 1;
	// if (fd < 0 || BUFFERSIZE <= 0 || read(fd,  &next_line, 0) < 0)
	// 	return (NULL);
	buffer = ft_calloc(3 + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 1);
	print_line(buffer);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line_buffer;

	line_buffer = read_files(fd);
	return (line_buffer);
}

#include <fcntl.h>
#include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*next_line;
// 	static int		count;

// 	count = 0;
// 	fd = open("example.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 	  printf("Error opening file");
// 	 return (1);
// 	} 
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (next_line == NULL)
// 			break ;
// 		count++;
// 		printf("[%d]:%s\n", count, next_line);
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
