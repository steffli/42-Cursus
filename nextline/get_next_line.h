#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
void		*ft_calloc(size_t count, size_t size);
void		print_line(char *buffer);
// char		*read_files(int fd);
void		ft_putstr(char *s);

#endif