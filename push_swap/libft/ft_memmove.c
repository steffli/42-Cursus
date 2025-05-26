/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:34:42 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 19:43:50 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: void dst, void src, size_t len

based on the whether the address of dst is smaller than src 
src is copied from back to front to dst to avoid overwriting values repeatedly
else it is copied normal from front to back

Returns dst with copied values from src based on given len
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned const char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}
