/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:47:07 by stliu             #+#    #+#             */
/*   Updated: 2025/04/03 18:12:36 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buffer)
{
	int		idx;
	char	*line;

	idx = 0;
	while (buffer[idx] && buffer[idx] != '\n')
		idx++;
	if (buffer[idx] == '\n')
		idx++;
	line = malloc((idx + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, buffer, idx + 1);
	return (line);
}

static char	*read_chunks(int fd)
{
	int				bytes_read;
	static char		buffer[BUFFER_SIZE + 1];
	static int		count;
	char			*line;

	line = "";
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(buffer), NULL);
	buffer[bytes_read] = '\0';
	while (*buffer != '\0')
	{
		if (*buffer == '\n')
			line = ft_substr(buffer, count, BUFFER_SIZE);
		else
			line = ft_strjoin(line, buffer);
		count++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line_buffer = read_chunks(fd);
	if (line_buffer == NULL)
		return (NULL);
	printf("%s", line_buffer);
	free(line_buffer);
	return (line_buffer);
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
		//printf("[%d]:%s\n", count, next_line);
		//free(next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
