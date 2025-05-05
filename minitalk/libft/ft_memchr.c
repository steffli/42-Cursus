/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:22:20 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 17:10:54 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: void pointer s, int , n

casts void s to unsigned char and then compares the value at i with c
then return the void pointer at position (p+i) since it always points
to the beginning of the pointer

Returns void pointer void pointer at p+i
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*p;

	i = 0;
	p = (unsigned const char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
