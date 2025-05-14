/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:28 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 16:13:47 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: string dst, string src, dstsize

takes two strings and concates the src to dst based on size
if the size is larger than dstlen then dstlen is updated to the val of size
then src is concatenated to the end of src and \0 added 

Returns the whole length of both strings it wanted to
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	j = dstlen;
	if (dstlen >= dstsize)
		dstlen = dstsize;
	if (dstsize > 0 && dstlen < dstsize - 1)
	{
		while (src[i] && (dstlen + i) < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}
