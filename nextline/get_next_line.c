/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:12:03 by stliu             #+#    #+#             */
/*   Updated: 2025/04/06 19:05:10 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(char **buffer)
{
	char	*line;
	char	*buf;
	size_t	i;

	i = 0;
	while ((*buffer)[i] != '\0' && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = ft_substr(*buffer, 0, i);
	if (line == NULL)
		return (NULL);
	buf = ft_substr(*buffer, i, ft_strlen(*buffer + i));
	free(*buffer);
	*buffer = buf;
	return (line);
}

static char	*get_line(int fd, char **buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(*buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp), NULL);
		temp[bytes_read] = '\0';
		*buffer = join_free(*buffer, temp);
		if (!*buffer)
			return (free(temp), NULL);
	}
	free(temp);
	if (ft_strlen(*buffer) == 0)
		return (free(*buffer), *buffer = NULL, NULL);
	return (fill_line(buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_strdup("");
	if (buffer == NULL)
		return (NULL);
	line = get_line(fd, &buffer);
	if (line == NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int 	fd;
// 	char 	*next_line;
// 	int 	count;

// 	count = 0;
// 	fd = open("example.txt", O_RDONLY);
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