/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:12:03 by stliu             #+#    #+#             */
/*   Updated: 2025/04/01 18:09:41 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*free_join(char *s1, char *s2)
{
	char	*joined;
	
	if (s1 == NULL || s2 == NULL)
		return (free(s1), NULL);
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

static char *fill_line(char **buffer)
{
	char	*line;
	char	*pos;
	char	*left_bytes;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	pos = ft_strchr(*buffer, '\n');
	if (pos)
	{
		len = pos - *buffer + 1;
		line = ft_substr(*buffer, 0, len);
		left_bytes = ft_strdup(pos + 1);
		free(*buffer);
		*buffer = left_bytes;
		return (line);
	}
	else if (*buffer && **buffer)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

static char	*read_line(int fd, char *buffer)
{
	int			bytes;
	char		*temp;
	char 		*new;

	bytes = 1;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes <= 0)
			{
				free(temp);
				if (bytes == 0)
					return (buffer);
				else
					return (NULL);
			}
		temp[bytes] = '\0';
		new = free_join(buffer, temp);
		if (!new)
			return (free(temp), NULL);
		buffer = new;
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = fill_line(&buffer);
	return (line);
}

