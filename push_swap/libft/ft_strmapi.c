/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:06:40 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 21:05:29 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: string s, function f that takes the index and the character

Iterate over the string and apply f to each character of s[i]
A new string is created therefore the *ptr needs fitting memory alloc

Return: newly created string with allocated memory for the chars
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	int		i;
	char	*ptr;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
