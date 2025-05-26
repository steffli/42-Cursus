/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:46:06 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 19:57:16 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
return substring from given s with the starting index of s 
also max len of substring is given
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= s_len)
	{
		ptr = ft_calloc(1, sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > s_len - start)
		len = s_len - start;
	ptr = ft_calloc((len + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
