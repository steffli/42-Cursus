/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:09:44 by stliu             #+#    #+#             */
/*   Updated: 2025/04/05 22:10:50 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_join(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

static int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_line(char *line, char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		temp = ft_substr(buffer, 0, i + 1);
		ft_memmove(buffer, buffer + i + 1, ft_strlen(buffer + i + 1) + 1);
	}
	else
	{
		temp = ft_strdup(buffer);
		buffer[0] = '\0';
	}
	if (!temp)
		return (free(line), NULL);
	if (line)
		return (free_join(line, temp));
	return (temp);
}

static char	*get_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	bytes_read;

	line = NULL;
	while (!find_newline(line))
	{
		if (!buffer[0])
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
			buffer[bytes_read] = '\0';
		}
		line = fill_line(line, buffer);
		if (!line)
			return (NULL);
	}
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = get_line(fd, buffer);
	if (!line || !line[0])
		return (free(line), NULL);
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