/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:12:03 by stliu             #+#    #+#             */
/*   Updated: 2025/05/04 17:21:58 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_and_clean(char *line, char *buffer)
{
	char	*new_line;

	new_line = ft_strjoin(line, buffer);
	free(line);
	return (new_line);
}

static char	*extract_complete_line(char *line, char *buffer, int *index)
{
	char	*result;
	int		line_end;

	line_end = *index;
	while (line[line_end] != '\0' && line[line_end] != '\n')
		line_end++;
	if (line[line_end] == '\n')
		line_end++;
	result = ft_substr(line, 0, line_end);
	if (result == NULL)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(buffer, &line[line_end], BUFFER_SIZE + 1);
	*index = 0;
	free(line);
	return (result);
}

static char	*read_until_newline(int fd, char *buffer, int *index)
{
	char	*line;
	ssize_t	bytes_read;

	line = ft_strdup(buffer);
	if (line == NULL)
		return (NULL);
	while (ft_strchr(&line[*index], '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = join_and_clean(line, buffer);
		if (line == NULL)
			return (NULL);
		*index = 0;
		if (!bytes_read)
			break;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	if (buffer[0] == '\0')
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
	}
	line = read_until_newline(fd, buffer, &index);
	if (line == NULL)
		return (NULL);
	while (line[index] != '\0' && line[index] != '\n')
		index++;
	if (line[index] == '\n')
		return (extract_complete_line(line, buffer, &index));
	if (line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
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