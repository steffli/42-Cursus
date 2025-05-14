/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:48:04 by stliu             #+#    #+#             */
/*   Updated: 2025/03/18 19:46:38 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: void pointer s1, void pointer s2 , n

casts void s1 and s2 to unsigned char and then compares the values at pos i
if p1 != p2 then the diff is returned for each i

Return: numerical diff between p1 and p2 for each i
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned const char		*p1;
	unsigned const char		*p2;

	p1 = (unsigned const char *)s1;
	p2 = (unsigned const char *)s2;
	i = 0;
	if (i == n)
		return (0);
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
