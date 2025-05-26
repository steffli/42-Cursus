/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:54:59 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 15:55:53 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: void pointer dst, void pointer src and size_t n
the void pointers are cast into unsigned and 
unsigned const char to access values 
then based of given n src is copied to dst
Returns void pointer dst with n values copied from src to dst
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned const char *)src;
	i = 0;
	if (!dest && !source)
		return (NULL);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
