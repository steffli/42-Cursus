/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:30:00 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 19:50:31 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: string haystack, string needle, len

two while loops to check if j++ of needle is part of the haystack 
if thats not the case increase i by one and repeat that again 
until the substring matches for all cases
return haystack if needle is not included

Return: haystack at the position where needle matches given len
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0] && i + needle_len <= len)
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
