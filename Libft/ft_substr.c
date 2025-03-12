/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:46:06 by stliu             #+#    #+#             */
/*   Updated: 2025/03/12 14:39:11 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
return substring from sgiven a starting index of s also max len of substring is given
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && count < len)
		{
			ptr[count] = s[i];
			count++;
		}
		i++;
	}
	ptr[count] = '\0';
	return (ptr);
}

// int main()
// {
// 	char str [] = "hallo";
// 	char *ptr = ft_substr(str, 2, 3);
// 	if (ptr) {
//         printf("%s\n", ptr);  // Should print "llo"
//         free(ptr);  // Don't forget to free the memory
//     }
//     return (0);
// }
