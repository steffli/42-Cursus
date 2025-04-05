/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:09:44 by stliu             #+#    #+#             */
/*   Updated: 2025/04/05 22:23:18 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (free(s1), NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

static char	*extract_line(char **buffer)
{
	size_t	i;
	char	*line;
	char	*new_buffer;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	line = ft_substr(*buffer, 0, i);
	if (!line)
		return (NULL);
	new_buffer = ft_substr(*buffer, i, ft_strlen(*buffer + i));
	free(*buffer);
	*buffer = new_buffer;
	return (line);
}

static char	*read_to_buffer(int fd, char **buffer)
{
	char	*temp;
	ssize_t	bytes_read;
	char	*line;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp), NULL);
		temp[bytes_read] = '\0';
		*buffer = ft_strjoin_gnl(*buffer, temp);
		if (!*buffer)
			return (free(temp), NULL);
	}
	free(temp);
	if (ft_strlen(*buffer) == 0)
		return (free(*buffer), *buffer = NULL, NULL);
	line = extract_line(buffer);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	line = read_to_buffer(fd, &buffer);
	if (!line)
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