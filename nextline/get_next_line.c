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


 char	*read_file(int fd)
{
	int			bytes;
	char		*buffer;
	static int	count;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = read_file(fd);
	return (buffer);
}

int	main(void)
{
	int 	fd;
	char 	*next_line;
	int 	count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
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