/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:48:04 by stliu             #+#    #+#             */
/*   Updated: 2025/03/12 11:33:57 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	size_t					i;
	unsigned const char		*p1;
	unsigned const char		*p2;

	p1 = (unsigned const char *)s1;
	p2 = (unsigned const char *)s2;
	i = 0;
	while (p1[i] && p2[i] && p1[i] == p2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
