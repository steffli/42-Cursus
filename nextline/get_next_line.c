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
	if (buffer == NULL)
		return (NULL);
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

static char	*read_chunks(int fd, char *cache)
{
	int				bytes_read;
	char			*buffer;

	while (!ft_strchr(cache, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer), cache);
		buffer[bytes_read] = '\0';
		cache = ft_strjoin(cache, buffer);
		free(buffer);
	}
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;
	char		*new_cache;
	int 		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cache = read_chunks(fd, cache);
	if (cache == NULL)
		return (NULL);
	line = get_line(cache);
	if (line == NULL)
		return (free(cache), cache = NULL, NULL);
	i = ft_strlen(line);
	if (cache[i] == NULL)
		return (free(cache), cache = NULL, line);
	else
	{
		new_cache = ft_strdup(cache + i);
		free(cache);
		cache = new_cache;
		if (cache == NULL)
			return (free(line), NULL);
	}
	return (line);
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
