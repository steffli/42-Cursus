/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:50:56 by stliu             #+#    #+#             */
/*   Updated: 2025/03/19 18:56:25 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Input: int n

integer input is converted into its string equivalent, the string
is filled from back to front. in case of neg int the - is written
as num[0]

Return: String representation of int n
*/
char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_number_len(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 1;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*num;
	long int	c;
	int			i;
	int			number_len;

	c = (long int)n;
	i = 0;
	number_len = ft_number_len(n);
	num = ft_calloc(number_len + 1, sizeof(char));
	if (num == NULL)
		return (NULL);
	if (c < 0)
	{
		c = -c;
		num[0] = '-';
		i = 1;
	}
	number_len--;
	while (c >= 10)
	{
		num[number_len--] = (c % 10) + '0';
		c /= 10;
	}
	num[number_len] = c + '0';
	return (num);
}
