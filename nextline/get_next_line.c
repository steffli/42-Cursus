/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:47:07 by stliu             #+#    #+#             */
/*   Updated: 2025/03/27 14:12:19 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytes_read;

	// if (fd < 0 || BUFFERSIZE <= 0 || read(fd,  &next_line, 0) < 0)
	// 	return (NULL);
	buffer = ft_calloc(BUFFERSIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if (bytes_read <= 0)
		return (NULL);
	return (buffer);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*next_line;
	static int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
	  printf("Error opening file");
	 return (1);
	} 
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free(next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
