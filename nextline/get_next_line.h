/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:38:31 by stliu             #+#    #+#             */
/*   Updated: 2025/04/06 15:42:05 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*join_free(char *s1, char *s2);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);

#endif